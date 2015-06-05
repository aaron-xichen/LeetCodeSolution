#include "../solution.h"
class Solution {
public:
    void reverseWords(string &s) {
        // trim the string first
        int begin = 0;
        int end = s.length()-1;
        while(s[begin] == ' ')
            begin++;
        while(s[end] == ' ')
            end--;
        s = s.substr(begin, end-begin+1);

        // reverse
        reverse(s.begin(), s.end());
        int i=0;
        int len = s.length();
        int ptr=0;
        int skip = 1;
        while(i<len-1){
            if(s[i] != ' ' && s[i+1] == ' '){
                copy(s, ptr, i);
                ptr += skip+1;
                skip = 1;
            }else if(s[i] != ' ' && s[i+1] != ' '){
                skip++;
            }
            i++;
        }
        copy(s, ptr, i);
        s = s.substr(0, ptr+skip);
    }

    void copy(string &s, int begin, int end){
        while(begin<end && s[end] != ' '){
            int tmp = s[begin];
            s[begin] = s[end];
            s[end] = tmp;
            begin++;
            end--;
        }
    }
};
