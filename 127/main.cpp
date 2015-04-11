#include "./solution2.cpp"
int main(){
    unordered_set<string> dict;
    dict.insert("hot");
    dict.insert("dot");
    dict.insert("dog");
    dict.insert("lot");
    dict.insert("log");
    solution sl = solution();
    int len = sl.ladderLength("hit", "cog", dict);
    cout<<len<<endl;
    // cout<<sl.isAdjacent("hot","log");
}
