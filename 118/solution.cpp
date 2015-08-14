#include "../solution.h"
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > all_solutions;
        if(numRows == 0){
            return all_solutions;
        }else if(numRows >= 1){
            vector<int> solution;
            solution.push_back(1);
            all_solutions.push_back(solution);
        }
        if(numRows == 1)
            return all_solutions;

        for(int i=1; i<numRows; i++){
            vector<int> solution;
            solution.push_back(1);
            vector<int> &last_solution = all_solutions[all_solutions.size()-1];
            int last_length = last_solution.size();
            for(int j=0; j<last_length; j++){
                int new_ele = last_solution[j] + ((j+1 < last_length) ? last_solution[j+1] : 0);
                solution.push_back(new_ele);
            }
            all_solutions.push_back(solution);
        }
        return all_solutions;
    }
};
