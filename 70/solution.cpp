#include "../solution.h"
class Solution {
public:
    int climbStairs(int n) {
        if(n == 0 || n == 1)
            return 1;
        else{
            int val[n];
            val[0] = 1;
            val[1] = 2;
            for(int i=2; i<n; i++){
                val[i] = val[i-1] + val[i-2];
            }
            return val[n-1];
        }
    }
};
