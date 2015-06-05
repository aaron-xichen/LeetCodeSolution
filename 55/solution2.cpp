#include "../solution.h"
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int farthest = 0;
        for(int i=0; i<len && i<=farthest; i++){
            farthest = max(farthest, i+nums[i]);
        }
        return farthest>=len-1;
    }
};
