#include "../solution.h"
class Solution {
public:
    int uniquePaths(int m, int n) {
        m = m -1;
        n = n -1;
        double result = 1.0;
        for(int i=1; i<=n; i++){
            result *= (double(m) + i ) / i;
        }
        return round(result);
    }
};
