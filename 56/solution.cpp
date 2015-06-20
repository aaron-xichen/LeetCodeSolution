#include "../solution.h"
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        map<int, int> itvls;
        int len = intervals.size();
        vector<Interval> result;
        for(int i=0; i<len; i++){
            int key = intervals[i].start;
            int value = intervals[i].end;
            if(itvls.find(key) == itvls.end())
                itvls.insert(pair<int, int>(intervals[i].start, intervals[i].end));
            else
                itvls.find(key)->second = max(itvls.find(key)->second, value);
        }

        for(auto it=itvls.begin(); it!=itvls.end(); ++it){
            int len = result.size();
            if(len == 0 || result[len-1].end < it->first)
                result.push_back(Interval(it->first, it->second));
            else{
                result[len-1].end = max(result[len-1].end, it->second);
            }
        }
        return result;
    }
};
