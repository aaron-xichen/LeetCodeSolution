#include "./solution.cpp"
int main(){

    // initialize the board
    char soduko[][9] = {
        {'.', '.', '8', '1', '9', '.', '.', '4', '5'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '7'},
        {'.', '9', '.', '.', '3', '2', '.', '.', '.'},
        {'.', '.', '.', '.', '5', '.', '.', '2', '9'},
        {'.', '.', '3', '.', '.', '.', '6', '.', '.'},
        {'6', '2', '.', '.', '4', '.', '.', '.', '.'},
        {'.', '.', '.', '7', '1', '.', '.', '5', '.'},
        {'8', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'2', '1', '.', '.', '6', '5', '8', '.', '.'},
    };
    vector<vector<char> > board;
    for(int i=0; i<9; i++){
        board.push_back(vector<char>(soduko[i], soduko[i]+9));
    }


    Solution sl = Solution();
    sl.solveSudoku(board);
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
