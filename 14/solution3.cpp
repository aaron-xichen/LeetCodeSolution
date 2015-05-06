#include "../solution.h"
class Solution{
    public:
        string longestCommonPrefix(vector<string> &strs){
            // trivial case
            if(strs.empty())
                return "";
            else if(strs.size() == 1)
                return strs[0];

            int len = 0;
            while(true){
                char c = '\0';
                for(int i=0; i<(int)strs.size(); i++){
                    if(len >= (int)strs[i].length())
                        return strs[0].substr(0, len);
                    else if(c == '\0')
                        c = strs[i][len];
                    else if(c != strs[i][len])
                        return strs[0].substr(0, len);
                }
                len++;
            }
        }
};
