#include "./solution2.cpp"
int main(){
    int candidate[] = {3,6,7,2};
    int len = sizeof(candidate)/sizeof(candidate[0]);
    vector<int> candidates(candidate, candidate+len);
    Solution sl = Solution();
    vector<vector<int> > solutions = sl.combinationSum(candidates, 13);

    for(vector<vector<int> >::iterator it=solutions.begin(); it!=solutions.end(); it++){
        for(vector<int>::iterator  itt=it->begin(); itt!=it->end(); itt++){
            cout<<*itt<<" ";
        }
        cout<<endl;
    }
}
