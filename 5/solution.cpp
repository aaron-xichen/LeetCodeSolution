#include "../solution.h"
class Solution {
public:
    string longestPalindrome(string s) {
        string longest = s.substr(0,1);
        int length = s.length();
        vector<int> trace;
        trace.push_back(0);
        trace.push_back(1);
        for(int i=1; i<length; i++){
            vector<int> next;
            next.push_back(0);
            next.push_back(1);
            for(int j=0; j<(int)trace.size(); j++){
                int idx = i - 1 - trace[j];
                if(idx >= 0 && s[i] == s[idx]){
                    next.push_back(trace[j] + 2);
                    if(trace[j] + 2 > (int)longest.length())
                        longest = s.substr(idx, trace[j]+2);
                }
            }
            trace = next;
        }
        return longest;
    }
};
