#include "../solution.h"
class Solution {
public:
    int calculateMinimumHP(vector<vector<int> >& dungeon) {
        int height = dungeon.size();
        int width = dungeon[0].size();
        vector<vector<int> > hps(height+1, vector<int>(width+1, INT_MAX));
        hps[height][width-1] = 1;
        hps[height-1][width] = 1;

        for(int i=height-1; i>=0; i--){
            for(int j=width-1; j>=0; j--){
                int need = min(hps[i][j+1], hps[i+1][j]) - dungeon[i][j];
                hps[i][j] = need <= 0 ? 1 : need;
            }
        }
        return hps[0][0];
    }
};
