#include "../solution.h"
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> r;
        if(nums.empty())
            return r;

        int start = nums[0];
        int pre = start;
        for(int i=1; i<(int)nums.size(); i++){
            int cur = nums[i];
            if(cur == pre + 1)
                pre = cur;
            else{
                if(start == pre)
                    r.push_back(to_string(start));
                else
                    r.push_back(to_string(start) + "->" + to_string(pre));
                start = cur;
                pre = start;
            }
        }
        if(start == pre)
            r.push_back(to_string(start));
        else
            r.push_back(to_string(start) + "->" + to_string(pre));
        return r;
    }
};
