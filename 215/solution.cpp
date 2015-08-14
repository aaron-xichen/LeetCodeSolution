#include "../solution.h"
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSort(nums, 0, nums.size()-1, k);
    }

    int quickSort(vector<int> &nums, int begin, int end, int k){
        if(begin == end)
            return nums[begin];
        else if( end - begin == 1 ){
            if(nums[begin] < nums[end])
                swap(nums[begin], nums[end]);
            return nums[begin+k-1];
        }else{
            int pivot = nums[begin];
            int left = begin+1;
            int right = end;
            while(left <= right){
                if(nums[left] > pivot){
                    left ++;
                }else{
                    swap(nums[left], nums[right--]);
                }
            }
            swap(nums[begin], nums[right]);

            int order = right - begin + 1;
            if(k == order)
                return pivot;
            else if(k > order){
                return quickSort(nums, right+1, end, k-order);
            }else{
                return quickSort(nums, begin, right-1, k);
            }
        }
    }
};
