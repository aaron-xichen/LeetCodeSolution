#include "../solution.h"
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int str_len = s.size();
        int word_num = words.size();
        if(str_len <= 0 || word_num <= 0)
            return ans;


        // init occurence
        unordered_map<string, int> fp;
        for(int i=0; i<word_num; i++)
            fp[words[i]] ++;

        int word_len = words[0].size();
        for(int i=0; i<word_len; i++){
            int cur = i;
            int counter = 0;
            int left = i;
            unordered_map<string, int> trace;
            while(cur <= str_len - word_len){
                string word = s.substr(cur, word_len);
                // cout<<"word: "<<word<< " left: "<<left<<" counter: "<<counter<<endl;
                cur += word_len;
                if(fp.count(word)){
                    trace[word]++;
                    counter++;
                    if(trace[word] > fp[word]){
                        while(true){
                            string remove_word = s.substr(left, word_len);
                            trace[remove_word] --;
                            counter --;
                            left += word_len;
                            if(remove_word == word){
                                break;
                            }
                        }
                    }
                    if(counter == word_num)
                        ans.push_back(left);
                }else{
                    trace.clear();
                    counter = 0;
                    left = cur;
                }
            }
        }
        return ans;
    }
};
