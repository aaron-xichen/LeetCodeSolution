#include "../solution.h"
class solution{
    public:
        int maxProfit(vector<int> &price){
            int size = price.size();
            if(0 == size) return 0;
            int K = 2;
            int dp[K+1][size];
            // no transaction, results in none profit
            for(int i=0; i<size; i++){
                dp[0][i] = 0;
            }
            // only one price, none profit even with many transaction
            for(int j=0; j<K+1; j++){
                dp[j][0] = 0;
            }

            // dp[i,j] = max{dp[i,j-1], dp[i-1,l]+price[j]-price[l]}, l=0,..., j-1
            // dp[i,j] = max{dp[i,j-1], max{dp[i-1,l]-price[l]} + price[j]}
            for(int i=1; i<K+1; i++){
                int tmp = dp[i-1][0] - price[0];
                for(int j=1; j<size; j++){
                    dp[i][j] = max(dp[i][j-1], tmp+price[j]);
                    tmp = max(tmp, dp[i-1][j] - price[j]);
                }
            }
            return dp[K][size-1];
        }
};
