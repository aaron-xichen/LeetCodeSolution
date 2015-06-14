#include "../solution.h"
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> trace;
        int len = nums.size();
        for(int i=0; i<len; i++)
            trace[nums[i]] = false;
        int longest = 0;
        for(int i=0; i<len; i++){
            int current_val = nums[i];
            if(!trace[current_val]){
                trace[current_val] = true;
                int counter = 1;
                for(int ele=current_val-1; trace.find(ele)!=trace.end() && !trace[ele];
                        trace[ele]=true,ele=ele-1, counter++);
                for(int ele=current_val+1; trace.find(ele)!=trace.end() && !trace[ele];
                        trace[ele]=true,ele=ele+1, counter++);
                longest = max(longest, counter);
            }
        }
        return longest;
    }
};
