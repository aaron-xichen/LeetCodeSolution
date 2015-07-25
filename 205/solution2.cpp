#include "../solution.h"
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char s2t[256];
        char t2s[256];
        memset(s2t, 0, sizeof(s2t));
        memset(t2s, 0, sizeof(t2s));
        for(int i=0; i<(int)s.size(); i++){
            char s_char = s[i];
            char t_char = t[i];
            if(s2t[(int)s_char] != '\0' && s2t[(int)s_char] != t_char)
                return false;
            if(t2s[(int)t_char] != '\0' && t2s[(int)t_char] != s_char)
                return false;
            s2t[(int)s_char] = t_char;
            t2s[(int)t_char] = s_char;
        }
        return true;
    }
};
