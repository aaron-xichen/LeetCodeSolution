#include "../solution.h"
class Solution {
public:
    int rob(vector<int>& nums) {
        int length = nums.size();
        if(length == 0)
            return 0;
        else if(length == 1)
            return nums[0];
        else if(length == 2)
            return max(nums[0], nums[1]);
        else if(length == 3)
            return max(nums[0] + nums[2], nums[1]);
        else{
            nums[2] += nums[0];
            for(int i=3; i<length; i++){
                nums[i] += max(nums[i-2], nums[i-3]);
            }
            return max(nums[length-1], nums[length-2]);
        }
    }
};
