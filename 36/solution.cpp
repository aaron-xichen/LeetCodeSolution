#include "../solution.h"
class Solution{
    public:
    bool isValidSudoku(vector<vector<char> > &board){
        for(int i=0; i<9; i++){
            if(!checkRow(i, board) || !checkCol(i, board) || !checkBox(i, board))
                return false;
        }
        return true;
    }

    bool checkRow(int row, vector<vector<char> > &board){
        unordered_set<char> set;
        for(int i=0; i<(int)board[row].size(); i++){
            if(board[row][i] == '.')
                continue;
            if(board[row][i] < '0' || board[row][i] > '9')
                return false;
            if(set.find(board[row][i]) != set.end())
                return false;
            set.insert(board[row][i]);
        }
        return true;
    }

    bool checkCol(int col, vector<vector<char> > &board){
        unordered_set<char> set;
        for(int i=0; i<(int)board.size(); i++){
            if(board[i][col] == '.')
                continue;
            if(board[i][col] < '0' || board[i][col] > '9')
                return false;
            if(set.find(board[i][col]) != set.end())
                return false;
            set.insert(board[i][col]);
        }
        return true;
    }

    bool checkBox(int num, vector<vector<char> > &board){
        int first_row = (num / 3) * 3;
        int first_col = (num % 3) * 3;
        unordered_set<char> set;
        for(int i=first_row; i<first_row+3; i++){
            for(int j=first_col; j<first_col+3; j++){
                if(board[i][j] == '.')
                    continue;
                if(board[i][j] < '0' || board[i][j] > '9')
                    return false;
                if(set.find(board[i][j]) != set.end())
                    return false;
                set.insert(board[i][j]);
            }
        }
        return true;
    }
};
