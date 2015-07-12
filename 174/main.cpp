#include "./solution2.cpp"
int main(){
    int row1[] = {-2, -3, 3};
    int row2[] = {-5, -10, 1};
    int row3[] = {10, 30, -5};

    vector<vector<int> > dungeon;
    vector<int> vec1(row1, row1+sizeof(row1)/sizeof(row1[0]));
    vector<int> vec2(row2, row2+sizeof(row2)/sizeof(row2[0]));
    vector<int> vec3(row3, row3+sizeof(row3)/sizeof(row3[0]));
    dungeon.push_back(vec1);
    dungeon.push_back(vec2);
    dungeon.push_back(vec3);

    Solution sl = Solution();
    cout<<sl.calculateMinimumHP(dungeon)<<endl;
}
