#include "../solution.h"
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        int height = obstacleGrid.size();
        int width = obstacleGrid[0].size();
        int trace[width+1];
        memset(trace, 0, sizeof(trace));
        trace[1] = 1;
        for(int i=0; i<height; i++){
            for(int j=1; j<=width; j++){
                if(obstacleGrid[i][j-1])
                    trace[j] = 0;
                else
                    trace[j] = trace[j-1] + trace[j];
            }
        }
        return trace[width];
    }
};
