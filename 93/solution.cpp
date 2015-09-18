#include "../solution.h"
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        vector<string> cur;
        recursion(ans, cur, s, 0);
        return ans;
    }

    void recursion(vector<string> &ans, vector<string> &cur, string &s, int idx){
        // cout<<cur.size() << " " << idx << endl;
        // not finish
        if(idx < (int)s.size() && cur.size() < 4){
            if(s[idx] == '0'){
                cur.push_back("0");
                recursion(ans, cur, s, idx + 1);
                cur.pop_back();
            }else{
                int len = 1;
                while(idx + len - 1 < (int)s.size() && stoi(s.substr(idx, len)) <= 255){
                    cur.push_back(s.substr(idx, len));
                    recursion(ans, cur, s, idx + len);
                    cur.pop_back();
                    len++;
                }
            }
        }else if(idx == (int)s.size() && cur.size() == 4){
            string sl = cur[0];
            for(int i=1; i<(int)cur.size(); i++){
                sl += "." + cur[i];
            }
            ans.push_back(sl);
        }
    }
};
