#include "../solution.h"
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 )
            return false;
        int x_original = x;
        int palindrome = 0;
        while(x){
            int r = x % 10;
            x = x / 10;
            palindrome = 10 * palindrome + r;
        }
        return x_original == palindrome;
    }
};
