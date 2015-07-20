#include "../solution.h"
// TLE
class Solution {
public:
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        vector<string> exist_words;
        for(int i=0; i<(int)words.size(); i++){
            if(exist(board, words[i]))
                exist_words.push_back(words[i]);
        }
        return exist_words;
    }

    bool exist(vector<vector<char> >& board, string word) {
        int board_height = board.size();
        int board_width = board[0].size();

        for(int i=0; i<board_height; i++){
            for(int j=0; j<board_width; j++){
                if(board[i][j] == word[0]){
                    char t = board[i][j];
                    board[i][j] = '\0';
                    bool is_exist = recursion(board, word, i, j, 1);
                    board[i][j] = t;
                    if(is_exist)
                        return true;
                }
            }
        }
        return false;
    }

    bool recursion(vector<vector<char> > &board, string word, int row_pos, int col_pos, int str_pos){
        if(str_pos == (int)word.length())
            return true;

        // top
        if(row_pos-1 >= 0 && board[row_pos-1][col_pos] == word[str_pos]){
            char t = board[row_pos-1][col_pos];
            board[row_pos-1][col_pos] = '\0';
            bool is_exist = recursion(board, word, row_pos-1, col_pos, str_pos+1);
            board[row_pos-1][col_pos] = t;
            if(is_exist)
                return true;
        }

        // bottom
        if(row_pos+1 <= (int)board.size()-1 && board[row_pos+1][col_pos] == word[str_pos]){
            char t = board[row_pos+1][col_pos];
            board[row_pos+1][col_pos] = '\0';
            bool is_exist = recursion(board, word, row_pos+1, col_pos, str_pos+1);
            board[row_pos+1][col_pos] = t;
            if(is_exist)
                return true;
        }

        // left
        if(col_pos-1 >=0 && board[row_pos][col_pos-1] == word[str_pos]){
            char t = board[row_pos][col_pos-1];
            board[row_pos][col_pos-1] = '\0';
            bool is_exist = recursion(board, word, row_pos, col_pos-1, str_pos+1);
            board[row_pos][col_pos-1] = t;
            if(is_exist)
                return true;
        }

        // right
        if(col_pos+1<=(int)board[0].size() && board[row_pos][col_pos+1] == word[str_pos]){
            char t = board[row_pos][col_pos+1];
            board[row_pos][col_pos+1] = '\0';
            bool is_exist = recursion(board, word, row_pos, col_pos+1, str_pos+1);
            board[row_pos][col_pos+1] = t;
            if(is_exist)
                return true;
        }
        return false;
    }
};
