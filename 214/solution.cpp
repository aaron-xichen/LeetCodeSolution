#include "../solution.h"
// LTE
class Solution {
public:
    string shortestPalindrome(string s) {
        int length = s.length();
        int i = length - 1;
        while(true){
            if(isPalindrome(s, 0, i) || --i <=0)
                break;
        }
        string sub_str = s.substr(i+1, length-i-1);
        sub_str.reserve();
        return sub_str + s;
    }

    bool isPalindrome(string s, int begin, int end){
        while(begin < end){
            if(s[begin++] != s[end--])
                return false;
        }
        return true;
    }
};
