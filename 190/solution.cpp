#include "../solution.h"
class Solution{
    public:
        uint32_t reverseBits(uint32_t n){
            uint32_t reverse = 0;
            // while(n != 0){
            for(int i=0; i<32; i++){
                int remainder = n % 2;
                reverse = (reverse << 1) + remainder;
                n = n / 2;
            }
            return reverse;
        }
};
