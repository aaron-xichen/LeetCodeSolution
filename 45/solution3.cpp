#include "../solution.h"
class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        // trivial case
        if(len == 0 || len == 1)
            return 0;
        int step = 1;
        int currentFarthestReach = nums[0];
        int nextFarthestReach = 0;
        int i = 0;
        while(currentFarthestReach < len - 1){
            for(; i<=currentFarthestReach; i++)
                nextFarthestReach = max(nextFarthestReach, i + nums[i]);
            currentFarthestReach = nextFarthestReach;
            step++;
        }
        return step;
    }
};
