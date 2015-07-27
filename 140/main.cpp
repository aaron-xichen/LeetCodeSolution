#include "./solution.cpp"
int main(){
    string s = "catsanddog";
    unordered_set<string> dict;
    dict.insert("cat");
    dict.insert("cats");
    dict.insert("and");
    dict.insert("sand");
    dict.insert("dog");

    Solution sl = Solution();
    vector<string> splits = sl.wordBreak(s, dict);
    for(int i=0; i<(int)splits.size(); i++){
        cout<<splits[i]<<endl;
    }
}
