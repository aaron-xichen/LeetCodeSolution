#include "../solution.h"
class solution{
    public:
        int minimumTotal(vector<vector<int> > &triangle){
            int height = triangle.size();
            if(0 == height) return 0;
            for(int i=1; i<height; i++){
                int len = triangle[i].size();
                for(int j=0; j<len; j++){
                    if(j == 0)
                        triangle[i][0] = triangle[i-1][0] + triangle[i][0];
                    else if(j == len-1)
                        triangle[i][len-1] = triangle[i-1][len-2] + triangle[i][len-1];
                    else{
                        int minimum = min(triangle[i-1][j-1], triangle[i-1][j]);
                        triangle[i][j] = triangle[i][j] + minimum;
                    }
                }
            }
            int minimumTotal = 100000;
            for(int j=0; j<(int)triangle[height-1].size(); j++){
                minimumTotal = min(minimumTotal, triangle[height-1][j]);
            }
            return minimumTotal;
        }
};
