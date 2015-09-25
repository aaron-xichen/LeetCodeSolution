#include "../solution.h"
class Solution {
public:
    int addDigits(int num) {
        return (num - 1) % 9 + 1;
        // if(num == 0)
            // return 0;
        // else if(num < 10)
            // return (num - 1) % 9 + 1;
        // else if(num < 100)
            // return (num - 10) % 9 + 1;
        // else if(num < 1000)
            // return (num - 100) % 9 + 1;
        // else if(num < 10000)
            // return (num - 1000) % 9 + 1;
        // else if(num < 100000)
            // return (num - 10000) % 9 + 1;
        // else if(num < 1000000)
            // return (num - 100000) % 9 + 1;
        // else if(num < 10000000)
            // return (num - 1000000) % 9 + 1;
        // else if(num < 100000000)
            // return (num - 10000000) % 9 + 1;
        // else if(num < 1000000000)
            // return (num - 100000000) % 9 + 1;
        // else
            // return (num - 1000000000) % 9 + 1;
    }
};
