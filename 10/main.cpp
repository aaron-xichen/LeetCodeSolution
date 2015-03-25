#include "solution.cpp"
int main(){
    const char*s = "aaa";
    const char*p = ".*";
    Solution solution = Solution();
    bool isMatch = solution.isMatch(s,p);
    cout<<isMatch<<endl;
}
