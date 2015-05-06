#include "../solution.h"
class Solution{
    public:
        vector<Interval> insert(vector<Interval> &intervals, Interval newInterval){
            // trivial case
            int size = intervals.size();
            // empty
            if(intervals.empty()){
                intervals.push_back(newInterval);
                return intervals;
            // intercross with all intervals
            }else{
                Interval first_interval = intervals[0];
                Interval last_interval = intervals[size-1];

                if(first_interval.start <= newInterval.end && newInterval.start <= first_interval.end &&
                            last_interval.start <= newInterval.end && newInterval.start <= last_interval.end){
                        newInterval.start = min(newInterval.start, first_interval.start);
                        newInterval.end = max(newInterval.end, last_interval.end);
                        vector<Interval> result;
                        result.push_back(newInterval);
                        return result;
                // insert at the begin
                }else if(newInterval.end < first_interval.start){
                    intervals.insert(intervals.begin(), newInterval);
                    return intervals;
                // insert at the end
                }else if(newInterval.start > last_interval.end){
                    intervals.push_back(newInterval);
                    return intervals;
                }
            }


            int left_most_index = -1;
            int right_most_index = -1;
            for(int i=0; i<size; i++){
                Interval current_interval = intervals[i];
                // not reach yet
                if(current_interval.end < newInterval.start)
                    continue;
                // no intercross
                else if(newInterval.end < current_interval.start){
                    right_most_index = i-1;
                    break;
                }else if(left_most_index == -1){
                    left_most_index = i;
                }else{
                    right_most_index = i;
                }
            }

            // no intercross at the tail
            if(-1 == left_most_index && -1 == right_most_index)
                cout<<"fatal error"<<endl;
            // no intercross in the middle
            else if(-1 == left_most_index && -1 != right_most_index)
                intervals.insert(intervals.begin()+right_most_index+1, newInterval);
            // intercross with only the last interval
            else if(-1 != left_most_index && -1 == right_most_index){
                Interval *last_interval = &intervals[left_most_index];
                last_interval->start = min(last_interval->start, newInterval.start);
                last_interval->end = max(last_interval->end, newInterval.end);
            // merge from left_most_index to right_most_index
            }else{
                newInterval.start = min(newInterval.start, intervals[left_most_index].start);
                newInterval.end = max(newInterval.end, intervals[right_most_index].end);
                for(int i=left_most_index; i<=right_most_index; i++){
                    intervals.erase(intervals.begin()+left_most_index);
                }
                intervals.insert(intervals.begin()+left_most_index, newInterval);
            }
            return intervals;
        }
};
