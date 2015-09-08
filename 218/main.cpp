#include "./solution.cpp"
int main(){
    // int b[][3] = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
    int b[][3] = {{0,5,7},{5,10,7},{5,10,12},{10,15,7},{15,20,7},{15,20,12},{20,25,7}};
    int len = sizeof(b) / sizeof(b[0]);
    vector<vector<int> > buildings(len, vector<int>(3));
    for(int i=0; i<len; i++){
        buildings[i].assign(b[i], b[i] + 3);
    }

    Solution sl = Solution();
    vector<pair<int, int> > p = sl.getSkyline(buildings);
    for(int i=0; i<(int)p.size(); i++){
        cout<<p[i].first<<", "<<p[i].second<<endl;
    }
}
