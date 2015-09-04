#include "../solution.h"
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        if(len < 3)
            return 0;
        int gap = INT_MAX;
        for(int i=0; i<len; i++){
            int remain = target - nums[i];
            int left = i + 1;
            int right = len - 1;
            while(left < right){
                int sum = nums[left] + nums[right];
                if(sum < remain){
                    if(remain - sum < abs(gap))
                        gap = sum - remain;
                    left++;
                }else if(sum > remain){
                    if( sum - remain < abs(gap))
                        gap = sum - remain;
                    right--;
                }else
                    return target;
            }
        }
        return target + gap;
    }
};
