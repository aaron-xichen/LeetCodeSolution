#include<iostream>
#include<vector>
using namespace std;
class solution{
    public:
        int maxArea(vector<int> &height){
            int lo = 0, hi=height.size()-1;
            int maxArea = 0;
            while(lo<hi){
                int area;
                if(height[lo]<height[hi]){
                    area = (hi-lo)*height[lo];
                    lo++;
                }else{
                    area = (hi-lo)*height[hi];
                    hi--;
                }
                if(area>maxArea)
                    maxArea = area;
            }
            return maxArea;
        }
};
