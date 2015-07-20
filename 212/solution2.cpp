#include "../solution.h"
struct TrieNode{
    TrieNode* children[26];
    string word;;
};

class Solution {
public:
    void insert(TrieNode* root, string word){
        for(int i=0; i<(int)word.size(); i++){
            int idx = word[i] - 'a';
            if(root->children[idx] == NULL)
                root->children[idx] = new TrieNode();
            root = root->children[idx];
        }
        root->word = word;
    }

    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(int i=0; i<(int)words.size(); i++){
            insert(root, words[i]);
        }
        int height = board.size();
        int width = board[0].size();
        unordered_set<string> exist_words;
        vector<vector<bool> > is_visited(height, vector<bool>(width, false));
        for(int i=0; i<height; i++){
            for(int j=0; j<width; j++){
                dfs(board, is_visited, i, j, root, exist_words);
            }
        }
        return vector<string>(exist_words.begin(), exist_words.end());
    }

    void dfs(vector<vector<char> >&board, vector<vector<bool> > &is_visited, int row, int col, TrieNode *pos, unordered_set<string> &exist_words){
        if(row < 0 || row > (int)board.size()-1 || col < 0 || col > (int)board[0].size()-1) return;
        TrieNode* next  = pos->children[board[row][col] - 'a'];
        if(is_visited[row][col] || NULL == next) return;
        if(next->word != "")
            exist_words.insert(next->word);

        is_visited[row][col] = true;
        dfs(board, is_visited, row+1, col, next, exist_words);
        dfs(board, is_visited, row-1, col, next, exist_words);
        dfs(board, is_visited, row, col+1, next, exist_words);
        dfs(board, is_visited, row, col-1, next, exist_words);
        is_visited[row][col] = false;
    }
};
