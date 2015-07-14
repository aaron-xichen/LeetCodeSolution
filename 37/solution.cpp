#include "../solution.h"
class Solution {
public:
    void solveSudoku(vector<vector<char> >& board) {
        vector<int> row(9, 0), col(9, 0), cell(9, 0);

        // config the board
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.')
                    continue;
                int offset = board[i][j] - '1';
                row[i] = row[i] | (1 << offset);
                col[j] = col[j] | (1 << offset);
                int cell_pos = 3*(i/3) + j/3;
                cell[cell_pos] = cell[cell_pos] | (1 << offset);
            }
        }
        recursion(0, row, col, cell, board, 0x000001ff);

    }

    bool recursion(int pos, vector<int> &row, vector<int> &col, vector<int> &cell,
            vector<vector<char> > &board, int bound){

        if(pos == 81) return true;
        int row_idx = pos / 9;
        int col_idx = pos % 9;

        if(board[row_idx][col_idx] == '.'){
            int cell_idx = 3*(row_idx/3) + col_idx/3;
            int ban = row[row_idx] | col[col_idx] | cell[cell_idx];
            while(true){
                int p = ~ban & (ban + 1);
                p = p & bound;
                if(!p) break;

                // setting
                row[row_idx] = row[row_idx] | p;
                col[col_idx] = col[col_idx] | p;
                cell[cell_idx] = cell[cell_idx] | p;
                char ava_int = log2(p) + '1';
                board[row_idx][col_idx] = ava_int;
                bool is_find = recursion(pos+1, row, col, cell, board, bound);
                if(is_find) return true;

                // rollback
                row[row_idx] = row[row_idx] & ~p;
                col[col_idx] = col[col_idx] & ~p;
                cell[cell_idx] = cell[cell_idx] & ~p;
                board[row_idx][col_idx] = '.';

                // update ban
                ban = ban | p;
            }
        }else{
            bool is_find = recursion(pos+1, row, col, cell, board, bound);
            if(is_find) return true;
        }
        return false;
    }
};
