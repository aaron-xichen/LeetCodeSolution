#include "../solution.h"

class Solution {
public:
    vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings) {
        vector<pair<int, int> > points;
        for(auto &p : buildings){
            points.push_back({p[0], -p[2]});
            points.push_back({p[1], p[2]});
        }
        sort(points.begin(), points.end());
        multiset<int> heap;
        heap.insert(0);
        vector<pair<int, int> > res;
        int pre = 0, cur = 0;
        for(auto &point: points){
            if(point.second < 0)
                heap.insert(-point.second);
            else
                heap.erase(heap.find(point.second));
            cur = *heap.rbegin();
            if(cur != pre){
                res.push_back({point.first, cur});
                pre = cur;
            }
        }
        return res;
    }
};
