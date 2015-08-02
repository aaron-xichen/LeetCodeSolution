#include "./solution.cpp"
int main(){
    Solution sl = Solution();
    vector<string> all = sl.letterCombinations("");
    for(int i=0; i<(int)all.size(); i++){
        cout<<all[i]<<" "<<endl;
    }
}
