#include "../solution.h"
// if t has no duplication
class Solution {
public:
    string minWindow(string s, string t) {
        int s_len = s.size();
        int t_len = t.size();
        int win_len = INT_MAX;
        string win = "";
        if(s_len <= 0 || t_len <= 0)
            return win;


        unordered_set<char> sets;
        for(int i=0; i<t_len; i++)
            sets.insert(t[i]);

        unordered_map<char, int> trace;
        int left = 0;
        for(int i=0; i<s_len; i++){
            char cur_char = s[i];
            // contains
            if(sets.count(cur_char)){
                // first add
                if(!trace.count(cur_char))
                    trace[cur_char] = i;
                // update
                else{
                    trace[cur_char] = i;
                    while(left < i ){
                        if(trace.count(s[left]) && left == trace[s[left]])
                            break;
                        left++;
                    }
                }

                if(trace.size() == sets.size()){
                    int new_len = i - left + 1;
                    if(new_len < win_len){
                        win_len = new_len;
                        win = s.substr(left, new_len);
                    }
                }
            }else if(left == i)
                left++;
        }
        return win;
    }
};
