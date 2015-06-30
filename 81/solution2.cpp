#include "../solution.h"
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while(left <= right){
            int mid = left + (right-left) / 2;
            if(nums[mid] == target)
                return true;
            if(nums[mid] > nums[left]){
                if(target >= nums[left] && target <= nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }else if(nums[mid] < nums[left]){
                if(target >= nums[mid] && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }else{
               left++;
            }
        }
        return false;
    }
};
