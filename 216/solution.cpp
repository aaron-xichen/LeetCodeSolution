#include "../solution.h"
class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        int digits[] = {1,2,3,4,5,6,7,8,9};
        vector<int> candidates(digits, digits+9);

        vector<vector<int> > solutions;
        vector<int> current_solution;
        recursion(candidates, 0, n, current_solution, solutions, k);
        return solutions;
    }

    void recursion(vector<int> &candidates, int pos, int target,
            vector<int> &current_solution, vector<vector<int> > &solutions, int k){

        if(target == 0 && k == 0){
            solutions.push_back(current_solution);
            return;
        }else if(k <=0 || pos == (int)candidates.size() || candidates[pos] > target || target < 0){
            return;
        }

        recursion(candidates, pos+1, target, current_solution, solutions, k);

        current_solution.push_back(candidates[pos]);
        recursion(candidates, pos+1, target-candidates[pos], current_solution, solutions, k-1);
        current_solution.pop_back();
    }
};
