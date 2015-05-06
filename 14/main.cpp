// #include "../solution.h"
#include "./solution3.cpp"
int main(){
    string str1 = "";
    string str2 = "";
    string str3 = "";

    vector<string> strs;
    strs.push_back(str1);
    strs.push_back(str2);
    strs.push_back(str3);


    Solution sl = Solution();
    cout<<sl.longestCommonPrefix(strs)<<endl;
}
