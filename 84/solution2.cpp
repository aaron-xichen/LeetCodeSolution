#include "../solution.h"
class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        height.push_back(0);
        int len = height.size();
        stack<int> trace;
        int i=0;
        int max_area = 0;
        while(i<len){
            if(trace.empty() || height[trace.top()] <= height[i])
                trace.push(i++);
            else{
                int t = trace.top();
                trace.pop();
                int new_value = height[t] * (trace.empty() ? i : (i-trace.top() -1));
                max_area = max(new_value, max_area);
            }
        }
        return max_area;
    }
};
