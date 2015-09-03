#include "../solution.h"
class Solution {
public:
    string minWindow(string s, string t) {
        int s_len = s.size();
        int t_len = t.size();
        int win_len = INT_MAX;
        string win = "";
        if(s_len <= 0 || t_len <= 0)
            return win;

        // compute the finger print of t
        unordered_map<char, int> fp;
        for(int i=0; i<t_len; i++){
            fp[t[i]]++;
        }


        unordered_map<char, int> trace;
        int counter = 0;
        int left = 0;
        for(int i=0; i<s_len; i++){
            char cur_char = s[i];

            // expand right bound
            if(fp.count(cur_char)){
                trace[cur_char]++;
                if(trace[cur_char] <= fp[cur_char])
                    counter ++;
                else{
                    // shrink left bound
                    while(true){
                        char char_left = s[left];
                        if(fp.count(char_left)){
                            if(trace[char_left] > fp[char_left])
                                trace[char_left]--;
                            else
                                break;
                        }
                        left++;
                    }
                }

                // find one solution
                if(counter == t_len){
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
