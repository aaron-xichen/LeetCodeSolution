#include "../solution.h"
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_ans = INT_MIN;
        int max_sofar = 0;
        for(int i=0; i<(int)nums.size(); i++){
            max_sofar = max(max_sofar + nums[i], nums[i]);
            max_ans = max(max_ans, max_sofar);
        }
        return max_ans;
    }
};
