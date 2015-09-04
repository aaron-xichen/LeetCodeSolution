#include "../solution.h"
class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> m;
        vector<vector<string> > ans;
        sort(strs.begin(), strs.end());
        for(int i=0; i<(int)strs.size(); i++){
            string key = strs[i];
            // cout<<"key:"<<key<<";"<<endl;
            sort(key.begin(), key.end());
            if(!m.count(key)){
                m.insert(pair<string, int>(key, m.size()));
                // m[key] = m.size();
                ans.resize(m.size());
            }
            // ans[m[key]].push_back(strs[i]);
            ans[m.find(key)->second].push_back(strs[i]);
        }
        return ans;
    }
};
