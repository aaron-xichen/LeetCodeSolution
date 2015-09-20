#include "../solution.h"
// MLE
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int len = s.length();
        map<string, int> m;
        for(int i=0; i<=len-10; i++){
            string sub = s.substr(i, 10);
            m[sub]++;
        }


        vector<string> ans;
        for(auto it=m.begin(); it != m.end(); it++){
            if(it->second >= 2)
                ans.push_back(it->first);
        }
        return ans;
    }
};
