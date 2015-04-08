#include "../solution.h"
class solution{
    public:
        int maxProfit(vector<int> &price){
            if(price.size() == 0) return 0;
            int min_price = price[0];
            int max_profit = 0;
            for(int i=1; i<(int)price.size(); i++){
                if(price[i] < min_price)
                    min_price = price[i];
                else{
                    int profit = price[i] - min_price;
                    max_profit = max(max_profit, profit);
                }
            }
            return max_profit;
        }
};
