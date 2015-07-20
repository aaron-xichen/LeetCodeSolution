#include "./solution2.cpp"
int main(){
    // string b[] = {"abc", "aed", "afg"};
    // string w[] = {"abcdefg","gfedcbaaa","eaabcdgfa","befa","dgc","ade"};
    string b[] = {"aa"};
    string w[] = {"a"};
    vector<string> words;
    for(int i=0; i<1; i++){
        words.push_back(w[i]);
    }
    vector<vector<char> > board;
    for(int i=0; i<1; i++){
        vector<char> one = vector<char>(b[i].begin(), b[i].end());
        board.push_back(one);
    }


    Solution sl = Solution();
    vector<string> exist_words = sl.findWords(board, words);
    for(int i=0; i<(int)exist_words.size(); i++){
        cout<<exist_words[i]<<endl;
    }
}
