#include "../solution.h"
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int> > solutions;
        vector<int> current_solution;
        recursion(candidates, 0, target, current_solution, solutions);
        return solutions;
    }

    void recursion(vector<int> &candidates, int pos, int target,
            vector<int> &current_solution, vector<vector<int> > &solutions){
        if(target == 0){
            solutions.push_back(current_solution);
            return;
        }

        if(pos == (int)candidates.size())
            return;

        int ele = candidates[pos];
        int num = target / ele;
        recursion(candidates, pos+1, target, current_solution, solutions);
        for(int i=1; i<=num; i++){
            current_solution.push_back(ele);
            recursion(candidates, pos+1, target-i*ele, current_solution, solutions);
        }
        for(int i=1; i<=num; i++)
            current_solution.pop_back();
    }
};
