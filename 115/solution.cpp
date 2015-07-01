#include "../solution.h"
class Solution {
public:
    int numDistinct(string s, string t) {
        int s_len = s.length();
        int t_len = t.length();

        int trace[t_len+1];
        memset(trace, 0, (t_len+1)*sizeof(trace[0]));
        trace[0] = 1;

        for(int i=1; i<s_len+1; i++){
            for(int j=min(i, t_len); j>0; j--){
                if(s[i-1] == t[j-1])
                    trace[j] = trace[j] + trace[j-1];
            }
        }
        return trace[t_len];
    }
};
