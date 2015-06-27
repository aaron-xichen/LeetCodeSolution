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
        for(int i=0; i<str_len; i++){
            begin_idx = max(begin_idx, idxs[(int)s[i]]+1);
            idxs[(int)s[i]] = i;
            max_length = max(max_length, i-begin_idx+1);
        }
        return max_length;
    }
};
