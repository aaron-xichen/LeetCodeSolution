#include "./solution.cpp"
int main(){
    Solution sl = Solution();
    vector<string> ans = sl.restoreIpAddresses("010010");
    for(int i=0; i<(int)ans.size(); i++){
        cout<<ans[i]<< " ";
    }
}
