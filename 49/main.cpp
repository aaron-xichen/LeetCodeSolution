#include "./solution2.cpp"
int main(){
    // string v[] = {"ef", "ass", "abz", "z", "aa"};
    string v[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    // string v[] = {""};
    vector<string> vs(v, v + sizeof(v) / sizeof(v[0]));

    Solution sl = Solution();
    vector<vector<string> > ans =  sl.groupAnagrams(vs);
    for(int i=0; i<(int)ans.size(); i++){
        for(int j=0; j<(int)ans[i].size(); j++){
            cout<<ans[i][j]<<", ";
        }
        cout<<endl;
    }

}
