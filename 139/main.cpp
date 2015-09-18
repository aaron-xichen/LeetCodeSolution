#include "./solution.cpp"
int main(){
    string s = "leetcode";
    unordered_set<string> wordDict;
    wordDict.insert("leet");
    wordDict.insert("code");

    Solution sl = Solution();
    cout<<sl.wordBreak(s, wordDict)<<endl;
}
