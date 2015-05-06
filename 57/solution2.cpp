#include "../solution.h"
class Solution{
    public:
        vector<Interval> insert(vector<Interval> &intervals, Interval newInterval){
            int idx = 0;
            int size = intervals.size();
            vector<Interval> new_result;
            for(;idx<size && intervals[idx].end < newInterval.start;idx++){
                new_result.push_back(intervals[idx]);
            }
            if(idx == size){
                new_result.push_back(newInterval);
                return new_result;
            }

            newInterval.start = min(newInterval.start, intervals[idx].start);
            for(;idx<size && intervals[idx].start <= newInterval.end;idx++){
                newInterval.end = max(newInterval.end, intervals[idx].end);
            }
            new_result.push_back(newInterval);

            for(;idx<size;idx++){
                new_result.push_back(intervals[idx]);
            }
            return new_result;
        }
};
