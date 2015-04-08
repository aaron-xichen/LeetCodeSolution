#include "../solution.h"
class solution{
    public:
        int maxProfit(int k, vector<int> &price){
            int size = price.size();
            if(0 == size || 0==k) return 0;

            int left = 0;
            int right = 0;
            vector<int> transactions;
            for(int i=0; i<(int)price.size() - 1; i++){
                if(price[i] >= price[i+1]){
                    if(price[left] != price[right])
                        transactions.push_back(price[right] - price[left]);
                    left = i+1;
                    right = i+1;
                }
                if(price[i] < price[i+1])
                    right = i+1;
            }
            if(price[left] != price[right])
                transactions.push_back(price[right] - price[left]);

            int sum = 0;
            if((int)transactions.size() <= k){
                for(int i=0; i<(int)transactions.size(); i++){
                    sum += transactions[i];
                }
                return sum;
            }

            // not abandunt
            int K = k;
            int dp[size];
            int dp_pre[size];
            // no transaction, results in none profit
            for(int i=0; i<size; i++){
                dp_pre[i] = 0;
            }

            // dp[i,j] = max{dp[i,j-1], dp[i-1,l]+price[j]-price[l]}, l=0,..., j-1
            // dp[i,j] = max{dp[i,j-1], max{dp[i-1,l]-price[l]} + price[j]}
            for(int i=1; i<K+1; i++){
                int tmp = dp_pre[0] - price[0];
                dp[0] = 0;
                for(int j=1; j<size; j++){
                    dp[j] = max(dp[j-1], tmp+price[j]);
                    tmp = max(tmp, dp_pre[j] - price[j]);
                }

                // copy array
                for(int i=0; i<size; i++){
                    dp_pre[i] = dp[i];
                }
            }
            return dp[size-1];
        }
};
