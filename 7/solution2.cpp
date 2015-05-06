#include "../solution.h"
class Solution{
    public:
        int reverse(int x){
            int reverse = 0;
            while(x != 0){
                int remainder = x % 10;
                int newReverse = 10 * reverse + remainder;
                if((newReverse - remainder) / 10 != reverse)
                    return 0;
                x = x / 10;
                reverse = newReverse;
            }
            return reverse;
        }
};
