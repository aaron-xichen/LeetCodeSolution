#include "./solution.cpp"
int main(){
    int s[] = {1,2,2};
    vector<int> S(s, s+sizeof(s)/sizeof(s[0]));
    Solution sl = Solution();
    vector<vector<int> > subsets = sl.subsets(S);
    for(int i=0; i<(int)subsets.size(); i++){
        for(int j=0; j<(int)subsets[i].size(); j++){
            cout<<subsets[i][j]<<" ";
        }
        cout<<endl;
    }
}
