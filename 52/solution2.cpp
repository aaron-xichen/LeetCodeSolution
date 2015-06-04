#include "../solution.h"
class Solution {
public:
    int totalNQueens(int n) {
        int solution_num = 0;
        int upper_bound = 0;
        for(int i=0; i<n; i++){
            upper_bound = (upper_bound << 1) + 1;
        }
        int row = 0;
        int left = 0;
        int right = 0;
        check(row, left, right, &solution_num, upper_bound);
        return solution_num;
    }

    void check(int row, int left, int right, int *solution_num, int upper_bound){
        if(row == upper_bound){
            *solution_num += 1;
            return;
        }else{
            int pos = ~(row | left | right) & upper_bound;
            while(pos){
                int p = pos & (~pos+1);
                pos = pos - p;
                check(row|p, (left|p)<<1, (right|p)>>1, solution_num, upper_bound);
            }
        }
    }
};
