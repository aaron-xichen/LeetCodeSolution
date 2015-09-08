#include "../solution.h"

// wrong
struct sort_buildings {
    bool operator()(const vector<int> &left, const vector<int> &right) {
        return left[2] > right[2];
    }
};

struct sort_point {
    bool operator()(const pair<int, int> &left, const pair<int, int> &right) {
        return left.first < right.first;
    }
};

class Solution {
public:
    vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings) {
        vector<pair<int, int> > ans;
        int len = buildings.size();
        if(len == 0)
            return ans;

        int begin_idx = 0;
        int right_bound = buildings[0][1];
        for(int i=1; i<=len; i++){
            if(i == len || buildings[i][0] > right_bound){
                int end_idx = i - 1;
                sort(buildings.begin() + begin_idx, buildings.begin() + end_idx + 1, sort_buildings());

                for(int l=begin_idx; l<=end_idx; l++)
                    cout<<buildings[l][0]<<", "<<buildings[l][1]<<", "<<buildings[l][2]<<endl;
                cout<<"--------"<<endl;

                int left = buildings[begin_idx][0];
                int right = buildings[begin_idx][1];
                ans.push_back(pair<int, int>(left, buildings[begin_idx][2]));

                for(int j = begin_idx + 1; j <= end_idx; j++){
                    int left_cur = buildings[j][0];
                    int right_cur = buildings[j][1];
                    int height_cur = buildings[j][2];
                    cout<<"left_cur:"<<left_cur<<" right_cur:"<<right_cur<<" height_cur:"<<height_cur<<endl;
                    if(right_cur > right){
                        ans.push_back(pair<int, int>(right, height_cur));
                        right = right_cur;
                    }
                    if(left_cur < left){
                        ans.push_back(pair<int, int>(left_cur, height_cur));
                        left = left_cur;
                    }
                }
                // last point on the ground
                ans.push_back(pair<int, int>(right, 0));

                // reset for next round
                if(end_idx + 1 <= len - 1){
                    right_bound = buildings[end_idx + 1][1];
                    begin_idx = end_idx + 1;
                }
            }else
                right_bound = max(right_bound, buildings[i][1]);
        }

        // remove duplicate point those have same height
        sort(ans.begin(), ans.end(), sort_point());
        vector<pair<int, int> > filtered;
        for(int i=0; i<(int)ans.size(); i++){
            cout<<ans[i].first<<";"<<ans[i].second<<endl;
            int size = filtered.size();
            if(0 != size && filtered[size-1].second == ans[i].second)
                continue;
            filtered.push_back(ans[i]);
        }
        return filtered;
    }
};
