#include "../solution.h"
// FAIL
// LTE
class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        // trivial case
        if(len == 0)
            return 0;
        vector<int> trace(len, 1000);
        trace[len-1] = 0;
        for(int i=len-2; i>=0; i--){
            int range = nums[i];
            if(i + range >= len-1)
                trace[i] = 1;
            else{
                int min_jump = INT_MAX;
                for(int j=range; j>=1; j--){
                    min_jump = min(min_jump, trace[i+j] + 1);
                }
                trace[i] = min_jump;
            }
        }
        return nums[0];
    }
};
