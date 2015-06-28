#include "../solution.h"
class Solution {
public:
    double myPow(double x, int n) {
        // trivial case
        if(x == 1)
            return 1;
        else if(x == -1){
            if(n % 2 == 0)
                return 1;
            else
                return -1;
        }

        if(n < 0)
            return recursion(1/x, -n);
        else
            return recursion(x, n);
    }

    double recursion(double x, int n){
        if(n == 0)
            return 1;
        else if(n % 2 ==0){
            double tmp = recursion(x, n/2);
            return tmp*tmp;
        }else{
            return x*recursion(x, n-1);
        }
    }
};
