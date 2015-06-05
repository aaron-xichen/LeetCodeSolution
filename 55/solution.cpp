#include "../solution.h"
// TLE
class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool is_visited[nums.size()];
        return recursion(nums, is_visited, 0);
    }

    bool recursion(vector<int>& nums, bool *is_visited, int pos){
        int max_jump = nums[pos];
        if(pos+max_jump>=(int)nums.size()-1)
            return true;
        for(int i=1; i<=max_jump; i++){
            bool is_ok = false;
            if(!is_visited[pos+max_jump]){
                is_ok = recursion(nums, is_visited, pos+i);
            }
            if(is_ok)
                return true;
        }
        is_visited[pos] = true;
        return false;
    }
};
