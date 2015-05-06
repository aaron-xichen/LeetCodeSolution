#include "../solution.h"
class Solution{
    public:
        int lengthOfLastWord(string s){
            int len = 0;
            int idx = s.length()-1;
            // remove space in the tail
            while(idx>=0){
                char c = s[idx];
                if(c == ' '){
                    idx--;
                }else{
                    break;
                }
            }
            // count non-space characters
            while(idx >=0 && s[idx--] != ' '){
                len++;
            }
            return len;
        }
};
