#include "./solution.cpp"
int main(){
    Solution sl = Solution();
    vector<vector<int> > solutions = sl.combinationSum3(3,9);
    for(vector<vector<int> >::iterator it=solutions.begin(); it!=solutions.end(); it++){
        for(vector<int>::iterator  itt=it->begin(); itt!=it->end(); itt++){
            cout<<*itt<<" ";
        }
        cout<<endl;
    }
}
