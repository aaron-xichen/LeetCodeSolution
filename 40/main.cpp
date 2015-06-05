#include "./solution.cpp"
int main(){
    int candidate[] = {10,1,2,7,6,1,5};
    int len = sizeof(candidate)/sizeof(candidate[0]);
    vector<int> candidates(candidate, candidate+len);
    Solution sl = Solution();
    vector<vector<int> > solutions = sl.combinationSum2(candidates, 8);

    for(vector<vector<int> >::iterator it=solutions.begin(); it!=solutions.end(); it++){
        for(vector<int>::iterator  itt=it->begin(); itt!=it->end(); itt++){
            cout<<*itt<<" ";
        }
        cout<<endl;
    }
}
