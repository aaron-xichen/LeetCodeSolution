#include "../solution.h"
class Solution {
public:
    string longestPalindrome(string s) {
        int longest_begin = 0;
        int longest_length = 1;
        int str_length = s.length();
        for(int i=0; i<str_length;){
            int j=i, k=i;
            while(k <str_length-1 && s[k] == s[k+1]) k++;
            i = k + 1;
            while(j>0 && k<str_length-1 && s[j-1] == s[k+1]){
                j--;
                k++;
            }
            int cur_len = k - j + 1;
            if(cur_len > longest_length){
                longest_begin = j;
                longest_length = cur_len;
            }
        }
        return s.substr(longest_begin, longest_length);
    }
};
