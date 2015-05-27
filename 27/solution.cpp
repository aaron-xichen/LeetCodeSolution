#include "../solution.h"
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // trivial case
        if(nums.empty())
            return 0;
        int head = 0;
        int tail = nums.size()-1;
        while(head < tail){
            if(nums[head] == val){
                nums[head] = nums[tail--];
            }else{
                head++;
            }
        }
        if(nums[head] == val)
            return head;
        else
            return head+1;
    }
};
