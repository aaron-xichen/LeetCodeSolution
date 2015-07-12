#include "../solution.h"
class Solution{
    public:
        vector<vector<int> > subsets(vector<int> &nums){
            sort(nums.begin(), nums.end());
            vector<vector<int> > all_solutions;
            vector<int> solution;
            recursion(all_solutions, solution, nums, 0);
            return all_solutions;
        }

        void recursion(vector<vector<int> >&all_solutions, vector<int> &solution, vector<int> &nums, int idx){
            if((int)nums.size() == idx){
                all_solutions.push_back(solution);
                return;
            }

            // exclude current value
            recursion(all_solutions, solution, nums, idx+1);

            // include current value
            solution.push_back(nums[idx]);
            recursion(all_solutions, solution, nums, idx+1);
            solution.pop_back();
        }
};
