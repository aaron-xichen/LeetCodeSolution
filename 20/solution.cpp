#include "../solution.h"
class Solution {
public:
    bool isValid(string s) {
        int len = s.length();
        // trivial case
        if(len == 0)
            return true;
        stack<char> p;
        for(int i=0; i<len; i++){
            // process current char
            char c = s[i];
            if( c == '(' || c == '{' || c == '[')
                p.push(c);
            else if(c == ')' || c == '}' || c == ']'){
                if(p.empty())
                    return false;
                char top = p.top();
                p.pop();
                if(c == ')' && top != '(')
                    return false;
                else if(c == '}' && top != '{')
                    return false;
                else if(c == ']' && top != '[')
                    return false;
            }else
                return false;

            // early stop
            if(len - i - 1< (int)p.size())
                return false;
        }
        return true;
    }
};
