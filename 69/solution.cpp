#include "../solution.h"
class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = 1<<15;
        while(left <= right){
            int mid = left + (right - left) / 2 ;
            int square = mid * mid;
            if(square == x)
                return mid;
            else if(square > x)
                right = mid - 1;
            else
                left = mid + 1;
        }
        cout<<"!"<<endl;
        return left;
    }
};
