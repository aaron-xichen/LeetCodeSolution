#include "../solution.h"
class Solution {
public:
    int numTrees(int n) {
        // trivial case
        if(n == 0 || n == 1)
            return 1;

        vector<int> trace(n+1, 0);
        trace[0] = 1;
        trace[1] = 1;
        for(int i = 2; i <= n; i++){
            int accu = 0;
            for(int j = 0; j < i; j++){
                accu += trace[j] * trace[i - 1 - j];
            }
            trace[i] = accu;
        }
        return trace[n];
    }
};
