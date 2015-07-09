#include "../solution.h"
class Solution {
public:
    int mySqrt(int x) {
        unsigned long long ans = 0;
        int bit = 1 << 16;
        while(bit){
            ans |= bit;
            if(ans * ans > x)
                ans ^= bit;
            bit >>= 1;
        }
        return ans;
    }
};
