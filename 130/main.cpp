#include "./solution.cpp"
int main(){
    vector<vector<char> > board;
    char row1[] = {'X', 'O', 'X', 'O', 'X', 'O'};
    char row2[] = {'O', 'X', 'O', 'X', 'O', 'X'};
    char row3[] = {'X', 'O', 'X', 'O', 'X', 'O'};
    char row4[] = {'O', 'X', 'O', 'X', 'O', 'X'};
    vector<char> r1(row1, row1+sizeof(row1)/sizeof(row1[0]));
    vector<char> r2(row2, row2+sizeof(row2)/sizeof(row2[0]));
    vector<char> r3(row3, row3+sizeof(row3)/sizeof(row3[0]));
    vector<char> r4(row4, row4+sizeof(row4)/sizeof(row4[0]));
    board.push_back(r1);
    board.push_back(r2);
    board.push_back(r3);
    board.push_back(r4);

    for(int i=0; i<(int)board.size(); i++){
        for(int j=0; j<(int)board[0].size(); j++){
            cout<<board[i][j];
        }
        cout<<endl;
    }

    solution sl = solution();
    sl.solve(board);

    for(int i=0; i<(int)board.size(); i++){
        for(int j=0; j<(int)board[0].size(); j++){
            cout<<board[i][j];
        }
        cout<<endl;
    }
}
