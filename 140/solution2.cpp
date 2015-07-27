#include "../solution.h"
class Solution {
    unordered_map<string, vector<string> > m;

public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        if(m.find(s) != m.end())
            return m.find(s)->second;
        vector<string> cur;
        if(wordDict.count(s))
            cur.push_back(s);
        for(int i=1; i<=(int)s.size(); i++){
            string sub_str = s.substr(0, i);
            if(wordDict.find(sub_str) != wordDict.end()){
                vector<string> res = wordBreak(s.substr(i), wordDict);
                for(int i=0; i<(int)res.size(); i++){
                    res[i] = sub_str + " " + res[i];
                }
                cur.insert(cur.end(), res.begin(), res.end());
            }
        }
        m.insert(pair<string, vector<string> >(s, cur));
        return cur;
    }
};
