#include "../solution.h"
class Solution {
public:
    int totalNQueens(int n) {
        int q[n];
        return recursion(q, 0, n);
    }

    int recursion(int *q, int row, int n_queen){
        int solution_num = 0;
        for(int i=0; i<n_queen; i++){
            if(check(q, row, i)){
                q[row] = i;
                if(row == n_queen-1)
                    solution_num += 1;
                else
                    solution_num += recursion(q, row+1, n_queen);
            }
        }
        return solution_num;
    }

    bool check(int *q, int i, int j){
        int m = 0;
        while(m<i){
            if(q[m] == j || i-m == abs(q[m]-j))
                return false;
            m++;
        }
        return true;
    }
};
