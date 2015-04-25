#include "./solution.cpp"
int main(){
    Solution sl = Solution();
    vector<vector<int> > matrix = sl.generateMatrix(4);
    for(int i=0; i<(int)matrix.size(); i++){
        for(int j=0; j<(int)matrix[0].size(); j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
