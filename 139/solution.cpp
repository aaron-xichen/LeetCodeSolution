#include "../solution.h"
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int len = s.length();
        vector<bool> trace(len + 1, false);
        trace[0] = true;
        for(int i=0; i<len; i++){
            for(int j=i-1; j>=-1; j--){
                if(trace[j + 1] && wordDict.find(s.substr(j + 1, i - j)) != wordDict.end()){
                    trace[i + 1] = true;
                    break;
                }
            }
        }
        return trace[len];
    }
};

