#include "../solution.h"
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        if(E>C || A>G || F>D || B>H)
            return (C-A)*(D-B) + (G-E)*(H-F);
        else
            return (C-A)*(D-B) + (G-E)*(H-F) - (min(C,G)-max(A,E))*(min(D,H)-max(B,F));
    }
};
