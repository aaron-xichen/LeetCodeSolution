#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;
// TLE
class Solution{
    public:
        vector<string> wordBreak(string s, unordered_set<string> &dict){
            int str_len = s.length();
            vector<vector<int> > trace(str_len, vector<int>());
            for(int i=0; i<str_len; i++){
                for(int j=i; j>=0; j--){
                    string sub_str = s.substr(j, i-j+1);
                    if(dict.find(sub_str) != dict.end()){
                        trace[i].push_back(j-1);
                    }
                }
            }
            vector<string> all_split;
            recusion(all_split, s, trace, str_len-1);
            return all_split;
        }

        void recusion(vector<string> &all_split, string s, vector<vector<int> > &trace, int pos){
            if(-1 == pos){
                all_split.push_back(s);
                return;
            }
            int size = trace[pos].size();
            for(int i=0; i<size; i++){
                int idx = trace[pos][i];
                if(-1 == idx){
                    all_split.push_back(s);
                }else{
                    string sp = string(s);
                    sp.insert(idx+1, " ");
                    recusion(all_split, sp, trace, idx);
                }
            }

        }
};
