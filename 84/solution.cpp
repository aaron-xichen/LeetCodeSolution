#include "../solution.h"
// TLE, O(n^2) time complexity
class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int len = height.size();
        int right_most[len], left_most[len];
        for(int i=0; i<len; i++){
            right_most[i] = i;
            left_most[i] = i;
        }

        for(int i=1; i<len; i++){
            int pass_through = height[i];
            for(int j=i-1; j>=0; j--){
                if(pass_through >= height[j] && right_most[j] == i-1){
                    right_most[j] = i;
                    pass_through = min(pass_through, height[j]);
                }
            }
        }

        for(int i=len-2; i>=0; i--){
            int pass_through = height[i];
            for(int j=i+1; j<len; j++){
                if(pass_through >= height[j] && left_most[j] == i+1){
                    right_most[j] = i;
                    pass_through = min(pass_through, height[j]);
                }
            }
        }

        int largest = INT_MIN;
        for(int i=0; i<len; i++){
            int value = (right_most[i] - left_most[i] + 1) * height[i];
            largest = max(largest, value);
        }
        return largest;
    }
};
