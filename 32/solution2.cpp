#include "../solution.h"
class Solution {
public:
    int longestValidParentheses(string s) {
        int length = s.size();
        // cout<<"len"<<length<<endl;
        int trace[length+1];
        for(int i=0; i<length+1; i++){
            trace[i] = 0;
        }
        int longest = 0;
        for(int i=1; i<length; i++){
            if(s[i] == ')' && s[i-1] == '('){
                trace[i+1] = 2 + trace[i-1];
            }else if(s[i] == ')' && s[i-1] == ')'){
                int inner_len = trace[i];
                if(inner_len > 0 &&
                        i-inner_len-1 >= 0 && s[i-inner_len-1] == '('){
                    trace[i+1] = 2 + inner_len + trace[i-inner_len-1];
                }
            }
            // cout<<s[i]<<" "<<trace[i+1]<<endl;
            longest = max(longest, trace[i+1]);
        }
        return longest;
    }
};
