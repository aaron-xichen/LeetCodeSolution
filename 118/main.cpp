#include "./solution.cpp"
int main(){

    Solution sl = Solution();
    vector<vector<int> > all_solutions = sl.generate(1);
    for(int i=0; i<(int)all_solutions.size(); i++){
        for(int j=0; j<(int)all_solutions[i].size(); j++){
            cout<<all_solutions[i][j]<< " ";
        }
        cout<<endl;
    }
}
