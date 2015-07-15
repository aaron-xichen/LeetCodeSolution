#include "../solution.h"
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> history;
        while(true){
            if(history.find(n) != history.end())
                return false;
            else
                history.insert(n);

            if(n == 1)
                return true;
            else{
                int new_n = 0;
                while(n){
                    new_n += (n % 10) * (n % 10);
                    n = n / 10;
                }
                n = new_n;
            }
        }
    }
};
