#include "../solution.h"
class Solution{
    public:
        void nextPermutation(vector<int> &nums){
            // trivial case
            int len = nums.size();
            if(1 == len)
                return;
            else if(2 == len){
                swap(nums, 0, 1);
                return;
            }

            int left_most_index = -1;
            for(int i=len-2; i>=0; i--){
                if(nums[i] < nums[i+1]){
                    left_most_index = i;
                    break;
                }
            }
            if(-1 == left_most_index)
                swap(nums, 0, len-1);
            else{
                int right_most_index = len-1;
                for(int i=left_most_index+1; i<len; i++){
                    if(nums[i] <= nums[left_most_index]){
                        right_most_index = i - 1;
                        break;
                    }
                }
                int tmp = nums[left_most_index];
                nums[left_most_index] = nums[right_most_index];
                nums[right_most_index] = tmp;

                swap(nums, left_most_index+1, len-1);
            }
        }
        void swap(vector<int> &num, int begin, int end){
            int len = num.size();
            if(begin >= end || begin >= len || end >= len)
                return;
            while(begin<end){
                int tmp = num[begin];
                num[begin] = num[end];
                num[end] = tmp;
                begin++;
                end--;
            }
        }
};
