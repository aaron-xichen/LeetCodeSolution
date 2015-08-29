#include "../solution.h"
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> idxs(2, -1);
        int left = 0;
        int right = nums.size() - 1;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid - 1;
            else if(nums[mid] == target && (mid == 0 || nums[mid - 1] != target)){
                idxs[0] = mid;
                break;
            }else{
                left = 0;
                right = mid - 1;
            }
        }

        if(idxs[0] == -1){
            if(nums[right] != target)
                return idxs;
            else
                idxs[0] = right;
        }

        left = 0;
        right = nums.size() - 1;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid - 1;
            else if(nums[mid] == target && (mid == (int)nums.size()-1 || nums[mid + 1] != target)){
                idxs[1] = mid;
                break;
            }else{
                left = mid + 1;
                right = nums.size() - 1;
            }
        }
        if(idxs[1] == -1)
            idxs[1] = right;
        return idxs;
    }
};
