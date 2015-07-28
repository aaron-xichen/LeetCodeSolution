#include "../solution.h"
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int i=0; i<(int)nums.size(); i++){
            auto it = m.find(nums[i]);
            if(it != m.end()){
                if(i - it->second <= k)
                    return true;
                it->second = i;
            }else{
                m.insert(pair<int,int>(nums[i], i));
            }
        }
        return false;
    }
};
