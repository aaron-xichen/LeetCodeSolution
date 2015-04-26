#include "./solution2.cpp"
int main(){
    int ratings[] = {2,3,4,1};
    int len = sizeof(ratings)/sizeof(ratings[0]);
    vector<int> ratings_vec(ratings, ratings+len);
    Solution sl = Solution();
    int candy_num = sl.noDuplicated(ratings_vec, 0, len-1);
    cout<<candy_num<<endl;
}
