#include "../solution.h"
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(t < 0 || k < 1) return false;
        unordered_map<long, int> m;
        for(int i=0; i<(int)nums.size(); i++){
            long bucket_id = ((long)nums[i] - INT_MIN) / ((long)t + 1);
            if(m.find(bucket_id) != m.end() ||
                    (m.find(bucket_id-1) != m.end() && ((long)nums[i] - m.find(bucket_id-1)->second <= t)) ||
                     (m.find(bucket_id+1) != m.end() && (m.find(bucket_id+1)->second - (long)nums[i] <= t)))
                return true;
            if((int)m.size() >= k){
                unsigned long long last_bucket_id = ((long)nums[i-k] - INT_MIN) / ((long)t + 1);
                m.erase(m.find(last_bucket_id));
            }
            m.insert(pair<long, int>(bucket_id, nums[i]));
        }
        return false;
    }
};
