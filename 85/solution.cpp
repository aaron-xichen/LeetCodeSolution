#include<iostream>
#include<vector>
using namespace std;
class solution{
    public:
        int maximalRectangle(vector<vector<char> > &matrix){
            if(matrix.size() == 0 || matrix[0].size()==0) return 0;
            int rlen = matrix.size();
            int clen = matrix[0].size();
            int height[clen], left[clen], right[clen];
            for(int i=0; i<clen; i++){
                height[i] = 0;
                left[i] = 0;
                right[i] = clen + 1;
            }
            int maxSize = 0;
            for(int i=0; i<rlen; i++){
                int curren_col = 0;
                for(int j=0; j<clen; j++){
                    if(matrix[i][j] == '0'){
                        curren_col = j+1;
                    }else{
                        if(height[j] == 0)
                            left[j] = curren_col;
                        else
                            left[j] = left[j] > curren_col ? left[j] : curren_col;
                    }
                }

                curren_col = clen+1;
                for(int j=clen-1; j>=0; j--){
                    if(matrix[i][j] == '0'){
                        curren_col = j + 1;
                    }else{
                        if(height[j] == 0)
                            right[j] = curren_col;
                        else
                            right[j] = right[j] < curren_col? right[j] : curren_col;
                    }
                }

                for(int j=0; j< clen; j++){
                    if(matrix[i][j] == '0')
                        height[j] = 0;
                    else{
                        height[j] = height[j] + 1;
                        int area =  height[j] * ( right[j] - left[j] - 1);
                        maxSize = (area > maxSize)? area : maxSize;
                    }
                }
            }
            return maxSize;
        }
};
