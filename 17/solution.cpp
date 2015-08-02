#include "../solution.h"
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int dial[9] = {0, 3, 6, 9, 12, 15, 19, 22, 26};
        vector<string> all_solutions;
        string current_solution = "";
        dfs(all_solutions, current_solution, digits, 0, dial);
        return all_solutions;
    }
    void dfs(vector<string> &all_solutions, string &current_solution,
            string digits, int pos, int *dial){
        if(pos == (int)digits.length()){
            if(pos != 0){
                all_solutions.push_back(current_solution);
            }
            return;
        }
        int cur_dig = digits[pos] - '0';
        if(cur_dig >=2 && cur_dig <=9){
            for(int i=dial[cur_dig-2]; i<dial[cur_dig-1]; i++){
                current_solution.push_back(i+'a');
                dfs(all_solutions, current_solution, digits, pos+1, dial);
                current_solution.pop_back();
            }
        }
    }
};
