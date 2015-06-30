#include "../solution.h"
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int len = nums.size() - 1;
        int right = len;
        while(left <= right){
            int mid = left + (right-left) / 2;
            if(nums[mid] == target || nums[left] == target || nums[right] == target)
                return true;

            // handle duplicate
            int skip = 0;
            while(mid-skip>left && nums[mid-skip]==nums[left] &&
                    mid+skip<right && nums[mid+skip]==nums[left])
                skip++;
            if(nums[mid-skip]!=nums[left] || nums[mid+skip]!=nums[left]){
                mid = nums[mid-skip] == nums[left] ? mid+skip : mid-skip;
                if(nums[mid] == target)
                    return true;
                if(nums[mid] > nums[left]){
                    if(target >= nums[left] && target <= nums[mid]){
                        left = left + 1;
                        right = mid - 1;
                    }else{
                        left = mid + 1;
                        right = right - 1;
                    }
                }else{
                    if(target >= nums[mid] && target <= nums[right]){
                        left = mid + 1;
                        right = right - 1;
                    }else{
                        left = left + 1;
                        right = mid - 1;
                    }
                }
            }else{
                if(mid-skip == left + 1){
                    left = mid + skip + 1;
                    right = right - 1;
                }else{
                    left = left + 1;
                    right = mid - skip -1;
                }

            }
        }
        return false;
    }
};
