#include "../solution.h"
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > all_solutions;
        if( numRows == 0)
            return all_solutions;
        else{
            vector<int> first;
            first.push_back(1);
            all_solutions.push_back(first);
        }
        for(int i=0; i<numRows; i++){
            int last_idx = max((int)all_solutions.size()-1, 0);
            vector<int> last_solution = all_solutions[last_idx];
            int last_len = last_solution.size();
            vector<int> new_solution;
            for(int j=0; j<last_len; j++){
                int new_ele = last_solution[j] + (j>0 ? last_solution[j-1] : 0);
                new_solution.push_back(new_ele);
            }
            new_solution.push_back(1);
            all_solutions.push_back(new_solution);
        }
        return all_solutions;
    }
};
