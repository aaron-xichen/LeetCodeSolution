#include "../solution.h"
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int ptr_0 = 0, ptr_2 = nums.size() - 1;
        for(int i=0; i<=ptr_2;) {
            if(nums[i] == 0)
                swap(nums[i++], nums[ptr_0++]);
            else if(nums[i] == 2)
                swap(nums[i], nums[ptr_2--]);
            else if(nums[i] == 1)
                i++;
        }
    }
};
