#include "../solution.h"
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        for(int i=0; i<len; i++){
            if( (i == 0 || nums[i] > nums[i-1])
                    && (i == len -1 || nums[i] > nums[i+1]))
                return i;
        }
        return -1;
    }
};
