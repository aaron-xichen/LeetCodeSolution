#include "../solution.h"
class Solution {
public:
    void reverseWords(string &s) {
        // trim the string first
        int begin = 0;
        int end = s.length()-1;
        while(begin <= end){
            if(s[begin] == ' '){
                begin++;
            }else if(s[end] == ' '){
                end--;
            }else{
                break;
            }
        }
        s = s.substr(begin, end-begin+1);

        // reverse
        reverse(s, 0, s.length()-1, s.length());
        int ptr = 0;
        int left = 0;
        int right = 0;
        for(int i=0; i<(int)s.length(); i++){
            if(s[i] == ' ' || i ==(int)s.length()-1){
                int l = right - left + 1;
                reverse(s, ptr, right-1, l);
                ptr += l;
                left = i + 1;
            }
            right = i;
        }
    }

    void reverse(string &s, int begin, int end, int len){
        while(begin<end && len > 0){
            char c = s[begin];
            s[begin] = s[end];
            s[end] = c;
            begin++;
            end--;
            len--;
        }
    }
};
