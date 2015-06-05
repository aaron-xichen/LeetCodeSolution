#include "../solution.h"
class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int> > solutions;
        vector<int> current_solution;
        recursion(candidates, 0, target, current_solution, solutions, true);
        return solutions;
    }

    void recursion(vector<int> &candidates, int pos, int target,
            vector<int> &current_solution, vector<vector<int> > &solutions, bool flag){

        if(target == 0){
            solutions.push_back(current_solution);
            return;
        }

        if(pos == (int)candidates.size())
            return;

        int ele = candidates[pos];
        if(ele > target)
            return;

        if(pos == 0 || candidates[pos-1] != ele || flag){
            recursion(candidates, pos+1, target, current_solution, solutions, false);
            current_solution.push_back(ele);
            recursion(candidates, pos+1, target-ele, current_solution, solutions, true);
            current_solution.pop_back();
        }else{
            recursion(candidates, pos+1, target, current_solution, solutions, false);
        }
    }
};
