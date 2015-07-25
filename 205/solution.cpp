#include "../solution.h"
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s2t;
        unordered_map<char, char> t2s;
        for(int i=0; i<(int)s.size(); i++){
            char s_char = s[i];
            char t_char = t[i];
            if(s2t.find(s_char) != s2t.end() && s2t.find(s_char)->second != t_char)
                return false;
            if(t2s.find(t_char) != t2s.end() && t2s.find(t_char)->second != s_char)
                return false;
            if(s2t.find(s_char) == s2t.end())
                s2t.insert(pair<char, char>(s_char, t_char));
            if(t2s.find(t_char) == t2s.end())
                t2s.insert(pair<char, char>(t_char, s_char));
        }
        return true;
    }
};
