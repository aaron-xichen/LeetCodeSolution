#include "../solution.h"
class Solution{
    public:
        int searchInsert(vector<int> &nums, int target){
            // trivial case
            int size = nums.size();
            if(0 == size || target <= nums[0])
                return 0;
            else if(target == nums[size-1])
                return size - 1;
            else if(target > nums[size-1])
                return size;
            int left = 0;
            int right = nums.size() - 1 ;
            while(left < right){
                int mid = (left + right) / 2;
                if(nums[mid] == target)
                    return mid;
                else if(nums[mid] > target)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            if(nums[right] >= target)
                return right;
            else
                return right + 1;
        }
};
