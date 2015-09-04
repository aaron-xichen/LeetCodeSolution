#include "../solution.h"
class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > m;
        for(int i=0; i<(int)strs.size(); i++){
            string sorted = strs[i];
            sort(sorted.begin(), sorted.end());
            m[sorted].push_back(strs[i]);
        }

        vector<vector<string> > ans;
        for(unordered_map<string, vector<string> >::iterator it=m.begin(); it != m.end(); it++){
            sort(it->second.begin(), it->second.end());
            ans.push_back(it->second);
        }
        return ans;
    }
};
