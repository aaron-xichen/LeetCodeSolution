#include "./solution.cpp"
int main(){
    Solution sl = Solution();
    vector<vector<string> > solutions = sl.solveNQueens(5);

    for(int i=0; i<(int)solutions.size(); i++){
        for(int j=0; j<(int)solutions[i].size(); j++){
            cout<<solutions[i][j]<<endl;
        }
        cout<<"------------"<<endl;
    }
}
