#include "../solution.h"
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // trivial case
        if(nums.empty())
            return 0;

        int length = nums.size();
        int tail = 0;
        int cur = 1;
        while(cur < length){
            if(tail > 0 && nums[cur] == nums[tail] && nums[tail] == nums[tail-1]){
                cur++;
            }else{
                nums[++tail] = nums[cur++];
            }
        }
        return tail+1;
    }
};
