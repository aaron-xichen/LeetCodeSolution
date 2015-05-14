#include "../solution.h"
class Solution {
public:
    bool isPalindrome(string s) {
        // trivial case
        int len = s.length();
        if(0 == len)
            return true;
        int i=0;
        int j=len-1;
        while(i<j){
            while(i<j && (s[i] < '0' || (s[i] > '9' && s[i] < 'A') || (s[i] > 'Z' && s[i] < 'a' ) || s[i] > 'z'))
                i++;
            if(i >= j)
                return true;
            while(i<j && (s[j] < '0' || (s[j] > '9' && s[j] < 'A') || (s[j] > 'Z' && s[j] < 'a' ) || s[j] > 'z'))
                j--;
            if(i >= j)
                return true;
            if(s[i] != s[j] && s[i] - s[j] != 'a'-'A' && s[j] - s[i] != 'a'-'A')
                return false;
            else{
                i++;
                j--;
            }
        }
        return true;
    }
};

