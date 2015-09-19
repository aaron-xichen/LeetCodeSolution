#include "../solution.h"
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int offset = 0;
        while(m != n){
            m = m >> 1;
            n = n >> 1;
            offset++;
        }
        return n << offset;
    }
};
