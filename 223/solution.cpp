#include "../solution.h"
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = (D-B) * (C-A);
        int area2 = (H-F) * (G-E);
        int cross = 0;
        // intersect
        if(C>=E && G>=A && H>=B && D>=F){
            int x[4] = {A, C, E, G};
            int y[4] = {B, D, F, H};
            vector<int> xx(x, x+sizeof(x)/sizeof(x[0]));
            vector<int> yy(y, y+sizeof(y)/sizeof(y[0]));
            sort(xx.begin(), xx.end());
            sort(yy.begin(), yy.end());
            cross = (xx[2] - xx[1]) * (yy[2] - yy[1]);
        }
        return area1 + area2 - cross;
    }
};
