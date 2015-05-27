#include "../solution.h"
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        for(int i=0; i<len; i++){
            while(nums[i]>0 && nums[i]<=len && nums[nums[i]-1]!=nums[i]){
                int tmp = nums[i];
                nums[i] = nums[tmp-1];
                nums[tmp-1] = tmp;
            }
        }

        for(int i=0; i<len; i++){
            if(nums[i] != i+1)
                return i+1;
        }
        return len+1;
    }
};
