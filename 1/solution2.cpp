#include "../solution.h"
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int> ans;
        if(len <= 1)
            return ans;

        unordered_map<int, int> m;
        for(int i=0; i<len; i++){
            int t = target - nums[i];
            if(m.count(t)){
                ans.push_back(m.find(t)->second);
                ans.push_back(i + 1);
                return ans;
            }else
                m.insert(pair<int, int>(nums[i], i+1));
        }
        return ans;
    }
};
