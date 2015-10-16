#include "../solution.h"
class Solution {
public:
    int countDigitOne(int n) {
        int val = 0;
        long long std = 1;
        while(n >= std){
            val += (n - std + 1) / (10 * std) * std + min((n - std + 1) % (10 * std), std);
            std *= 10;
        }
        return val;
    }
};
