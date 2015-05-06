#include "../solution.h"
class Solution{
    public:
        string longestCommonPrefix(vector<string> &strs){
            // trivial case
            if(strs.empty())
                return "";
            else if(strs.size() == 1)
                return strs[0];
            string longest = longestOfTwo(strs[0], strs[1]);
            for(int i=2; i<(int)strs.size(); i++){
                if(longest.empty())
                    return longest;
                longest = longestOfTwo(longest, strs[i]);
            }
            return longest;
        }

        string longestOfTwo(string &str1, string &str2){
            int idx = 0;
            if(!str1.empty() && !str2.empty())
                while(str1[idx] == str2[idx])
                    idx++;
            else
                return "";
            return str1.substr(0, idx);
        }

};
