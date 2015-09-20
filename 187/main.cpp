#include "./solution3.cpp"
int main(){
    Solution sl = Solution();
    vector<string> ans = sl.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    for(int i=0; i<(int)ans.size(); i++){
        cout<< ans[i] << " ";
    }
}
