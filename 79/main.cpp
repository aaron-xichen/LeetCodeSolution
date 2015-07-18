#include "./solution.cpp"
int main(){
    // string b[]= {
        // "ccbbcaabccbc",
        // "bcbbbbcaacca",
        // "ccabbabbaabb",
        // "cbababbabcbc",
        // "baacaccacccc",
        // "abacabbcabbb",
        // "cabbaaacbbbc",
        // "bcbccbbbbcab",
        // "bcacacaaacbb",
        // "acbcbaaaccaa",
        // "abbbacacbabb"};
    // string word = "cbbcacacaabca";
    string b[] = {"aaaa", "aaaa", "aaaa"};
    string word = "aaaaaaaaaaaaa";
    vector<vector<char> > board;
    for(int i=0; i<3; i++){
        vector<char> one = vector<char>(b[i].begin(), b[i].end());
        board.push_back(one);
    }


    Solution sl = Solution();
    cout<<sl.exist(board, word)<<endl;


}
