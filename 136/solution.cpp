#include "../solution.h"
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int i=0; i<(int)nums.size(); i++){
            result ^= nums[i];
        }
        return result;
    }
};
