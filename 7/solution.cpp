#include "../solution.h"
class Solution{
    public:
        int reverse(int x){
            // trivial case
            if(x == -2147483648)
                return 0;

            int reverse = 0;
            bool isNegative = false;
            if(x < 0){
                isNegative = true;
                x = -x;
            }
            while(x > 0){
                int remainder = x % 10;
                // overflow
                if(reverse > 214748364 || (reverse == 214748364 && remainder == 9))
                    return 0;
                reverse = 10 * reverse + remainder;
                x = x / 10;
            }
            if(isNegative)
                return -reverse;
            else
                return reverse;
        }
};
