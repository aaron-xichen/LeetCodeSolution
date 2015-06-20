#include "../solution.h"
class Solution {
public:
    static bool compare(Interval &invl1, Interval &invl2){
        return invl1.start > invl2.start;
    }

    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        int len = intervals.size();
        vector<Interval> result;
        for(int i=0; i<len; i++){
            Interval ivl = intervals[i];
            int size = result.size();
            if(size == 0 || result[size-1].end < ivl.start)
                result.push_back(ivl);
            else
                result[size-1].end = max(result[size-1].end, ivl.end);
        }
        return result;
    }
};
