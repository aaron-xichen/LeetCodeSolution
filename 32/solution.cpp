#include "../solution.h"
class Solution {
public:
    int longestValidParentheses(string s) {
        int sc[20000];
        int LEFTPAR = -2;
        int RIGHTPAR = -1;
        int pos = -1;
        for(int i=0; i<(int)s.size(); i++){
            char cur_char = s[i];
            if(cur_char == ')'){
                if(pos == -1){
                    sc[++pos] = RIGHTPAR;
                }else if(sc[pos] == LEFTPAR){
                    sc[pos] = 2;
                }else if(sc[pos] == RIGHTPAR){
                    sc[++pos] = RIGHTPAR;
                }else if(pos == 0){
                    sc[++pos] = RIGHTPAR;
                }else if(sc[pos-1] == LEFTPAR){
                    sc[pos-1] = sc[pos] + 2;
                    pos--;
                }else{
                    sc[++pos] = RIGHTPAR;
                }

                // merge adjacent number
                if(pos >= 1 && sc[pos]>=2 && sc[pos-1]>=2){
                    sc[pos-1] = sc[pos-1] + sc[pos];
                    pos--;
                }
            }else{
                sc[++pos] = LEFTPAR;
            }
        }

        int longest = 0;
        for(int i=0; i<=pos; i++){
            longest = max(longest, sc[i]);
        }
        return longest;
    }
};
