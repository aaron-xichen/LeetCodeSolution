#include "../solution.h"
class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        // trivial case
        if(size <= 2)
            return 0;

        int peaks[size];
        int peak = height[0];
        for(int i=1; i<size; i++){
            peak = max(peak, height[i]);
            peaks[i] = peak;
        }
        peak = height[size-1];
        for(int i=size-2; i>=0; i--){
            peak = max(peak, height[i]);
            peaks[i] = min(peaks[i], peak);
        }
        int total = 0;
        for(int i=1; i<size-1; i++){
            total += peaks[i] - height[i];
        }
        return total;
    }
};
