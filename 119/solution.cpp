#include "../solution.h"
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> trace(rowIndex+1, 0);
        trace[0] = 1;
        for(int i=1; i<=rowIndex; i++){
            for(int j=i; j>=0; j--){
                trace[j] = trace[j] + (j-1>=0 ? trace[j-1] : 0);
            }
        }
        return trace;
    }
};
