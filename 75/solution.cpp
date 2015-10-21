#include "../solution.h"
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int ptr_0 = 0, ptr_1 = 0;
        for(int i=0; i<(int)nums.size(); i++){
            if(nums[i] == 1)
                swap(nums[i], nums[ptr_1++]);
            else if(nums[i] == 0){
                nums[i] = nums[ptr_1];
                nums[ptr_1] = nums[ptr_0];
                nums[ptr_0] = 0;
                ptr_0++;
                ptr_1++;
            }
        }
    }
};
