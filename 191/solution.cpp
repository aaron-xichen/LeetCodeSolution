#include "../solution.h"
class Solution{
    public:
        int hammingWeight(uint32_t n){
            int total = 0;
            uint32_t original_value = n;
            uint32_t bound = 2;
            for(int i=0; i<32; i++){
                total += n % 2;
                n = n / 2;
                if(original_value < bound)
                    break;
                bound = bound * 2;
            }
            return total;
        }

};
