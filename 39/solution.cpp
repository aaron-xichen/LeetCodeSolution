#include "../solution.h"
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        reverse(candidates.begin(), candidates.end());

        vector<vector<int> > solutions;
        unordered_map<int, vector<vector<int> > > cached;
        vector<int> current_solution;
        recursion(candidates, 0, target, current_solution, cached);
        return solutions;
    }

    bool recursion(vector<int> &candidates, int pos, int target,
            vector<int> current_solution,
            unordered_map<int, vector<vector<int> > > &cached){

        // use cache
        if(cached.find(target) != cached.end())
            return true;

        int ele = candidates[pos];

        // last element
        if(pos == (int)candidates.size()-1){
            if(target  % ele == 0){
                int nums = target / ele;
                for(int i=0; i<nums; i++){
                    current_solution.push_back(ele);
                }
                vector<vector<int> > current_solution_wrap;
                current_solution_wrap.push_back(current_solution);
                cached[target] = current_solution_wrap;
                return true;
            }else{
                return false;
            }
        }

        // normal recurison
        int nums = target / ele;
        vector<vector<int> > collections;
        for(int i=0; i<=nums; i++){
            if(i > 0)
                current_solution.push_back(ele);
            int next_target = target - i * ele;
            bool is_ok = recursion(candidates, pos+1, next_target, current_solution, cached);
            if(is_ok){
                vector<vector<int> > *cached_solutions = &cached[next_target];
                for(vector<vector<int> >::iterator it=cached_solutions->begin(); it!=cached_solutions->end(); ++it){
                    collections.push_back(*it);
                }

            }
        }

        if(collections.empty())
            return false;
        else{
            for(auto it=collections.begin(); it!=collections.end(); ++it){
                it->insert(it->begin(), )
            }
            cached[target] = collections;
            return true;
        }
    }
};
