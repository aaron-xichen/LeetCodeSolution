#include "../solution.h"
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> all_solutions;
        all_solutions.push_back(0);
        for(int i=0; i<n; i++){
            int len = all_solutions.size();
            for(int j=len-1; j>=0; j--){
                all_solutions.push_back(all_solutions[j] + (1 << i));
            }
        }
        return all_solutions;
    }
};
