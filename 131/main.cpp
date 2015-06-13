#include "./solution.cpp"
int main(){
    Solution sl = Solution();
    vector<vector<string> > all_strs;
    all_strs = sl.partition("aab");
    for(int i=0; i<(int)all_strs.size(); i++){
        for(int j=0; j<(int)all_strs[i].size(); j++){
            cout<<all_strs[i][j]<<" ";
        }
        cout<<endl;
    }
}
