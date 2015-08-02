#include "../solution.h"
class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_str = s;
        reverse(rev_str.begin(), rev_str.end());
        string l_str = s + "#" + rev_str;
        int length = l_str.length();
        vector<int> trace(length, 0);
        for(int i=1; i<length; i++){
            int j = trace[i-1];
            while(j > 0 && l_str[j] != l_str[i])
                j = trace[j-1];
            trace[i] = (j + (l_str[i] == l_str[j]));
        }
        return rev_str.substr(0, rev_str.length()-trace[length-1]) + s;
    }
};
