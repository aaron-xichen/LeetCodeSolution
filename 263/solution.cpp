#include "../solution.h"
class Solution {
public:
    bool isUgly(int num) {
        if(num == 0)
            return false;

        // divide 30
        while(num % 30 == 0)
            num /= 30;

        // divide 15
        while(num % 15 == 0)
            num /= 15;

        // divide 10
        while(num % 10 == 0)
            num /= 10;

        // divide 6
        while(num % 6 == 0)
            num /= 6;

        // diviede 5
        while(num % 5 == 0)
            num /= 5;

        // divide 3
        while(num % 3 == 0)
            num /= 3;

        // divide 2
        while(num % 2 == 0)
            num /= 2;

        return num == 1;
    }
};

