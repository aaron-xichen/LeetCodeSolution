#include "../solution.h"
class solution{
    public:
        int maxProfit(vector<int> &price){
            if(price.size() == 0) return 0;
            int left = 0;
            int right = 0;
            int sum = 0;
            for(int i=0; i<(int)price.size() - 1; i++){
                if(price[i] >= price[i+1]){
                    if(price[left] != price[right])
                        sum += price[right] - price[left];
                    left = i+1;
                    right = i+1;
                }
                if(price[i] < price[i+1])
                    right = i+1;
            }
            if(price[left] != price[right])
                sum += price[right] - price[left];
            return sum;
        }
};
