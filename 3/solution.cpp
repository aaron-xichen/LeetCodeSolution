#include "../solution.h"
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int str_len = s.length();
        int CHARNUM = 256;
        int idxs[CHARNUM];
        int begin_idx = 0;
        int max_length = 0;
        memset(idxs, -1, CHARNUM*sizeof(idxs[0]));
        // for(int i=0; i<CHARNUM; i++)
            // idxs[i] = -1;
        for(int i=0; i<str_len; i++){
            char c = s[i];
            int old_idx = idxs[(int)c];
            if(old_idx != -1){
                max_length = max(max_length, i-begin_idx);
                for(int j=begin_idx; j<=old_idx; j++){
                    idxs[(int)s[j]] = -1;
                }
                begin_idx = old_idx + 1;
            }
            idxs[(int)c] = i;
        }
        max_length = max(max_length, str_len-begin_idx);
        return max_length;
    }
};
