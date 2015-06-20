#include "../solution.h"
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        int max_value = nums[0];
        int max_pre = nums[0];
        int min_pre = nums[0];
        int maxhere, minhere;
        for(int i=1; i<len; i++){
            int ele = nums[i];
            maxhere = max(max(max_pre*ele, min_pre*ele), ele);
            minhere = min(min(max_pre*ele, min_pre*ele), ele);
            max_value = max(max_value, maxhere);
            max_pre = maxhere;
            min_pre = minhere;
        }
        return max_value;
    }
};
