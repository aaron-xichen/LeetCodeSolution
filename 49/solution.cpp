#include "../solution.h"
// wrong answer
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> indices;
        if(words.empty())
            return indices;

        int word_len = words[0].length();
        int str_len = s.length();
        int words_num = words.size();
        int cur = 0;

        // cout<<"words_num: "<<words_num<<endl;
        // cout<<"word_len: "<<word_len<<endl;
        // the end index of each word
        unordered_map<string, int> trace;
        for(int i=0; i<words_num; i++){
            trace.insert(pair<string, int>(words[i], -1));
        }

        int begin_idx = 0;
        while(cur < str_len){
            string word = s.substr(cur, word_len);
            // cout<<cur<<" "<<word<<endl;
            unordered_map<string, int>::iterator it = trace.find(word);
            if(it == trace.end()){
                cur++;
                begin_idx = cur;
                continue;
            }
            begin_idx = max(begin_idx, it->second + 1);
            // cout<<"begin_idx: " << begin_idx<<endl;
            it->second = cur + word_len - 1;
            if(cur - begin_idx  == (words_num - 1) * word_len)
                indices.push_back(begin_idx);
            cur += word_len;
        }
        return indices;
    }
};
