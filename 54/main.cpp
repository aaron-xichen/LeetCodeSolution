#include "./solution.cpp"
int main(){
    int row1[] = {1,2,3};
    int row2[] = {5,6,7};
    int row3[] = {9,10,11};
    int row4[] = {13,14,15};

    vector<int> row1_vec(row1, row1+sizeof(row1)/sizeof(row1[0]));
    vector<int> row2_vec(row2, row2+sizeof(row2)/sizeof(row2[0]));
    vector<int> row3_vec(row3, row3+sizeof(row3)/sizeof(row3[0]));
    vector<int> row4_vec(row4, row4+sizeof(row4)/sizeof(row4[0]));

    vector<vector<int> > board;
    board.push_back(row1_vec);
    board.push_back(row2_vec);
    board.push_back(row3_vec);
    board.push_back(row4_vec);

    Solution sl = Solution();
    vector<int> result = sl.spiralOrder(board);
    for(int i=0; i<(int)result.size(); i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
}
