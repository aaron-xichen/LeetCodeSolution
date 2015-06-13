#include "../solution.h"
class Solution {
public:
    vector<vector<string> > partition(string s) {
        int len = s.length();
        vector<vector<bool> > trace_matrix(len, vector<bool>(len, false));
        for(int c=0; c<len; c++){
            // odd
            for(int l=0; c-l>=0 && c+l<len && s[c-l] == s[c+l]; l++)
                trace_matrix[c-l][c+l] = true;

            // even
            if(c-1>=0 && s[c-1] == s[c])
                for(int l=0; c-1-l>=0 && c+l<len && s[c-1-l]==s[c+l]; l++)
                    trace_matrix[c-1-l][c+l] = true;
        }

        // for(int i=0; i<len; i++){
            // for(int j=0; j<len; j++){
                // cout<<trace_matrix[i][j]<<" ";
            // }
            // cout<<endl;
        // }

        vector<vector<string> > all_strs;
        vector<string> new_str;
        recurison(s, trace_matrix, all_strs, new_str, 0);
        return all_strs;
    }

    void recurison(string s, vector<vector<bool> > &trace_matrix, vector<vector<string> > &all_strs, vector<string> &new_str, int k){
        int len = trace_matrix.size();
        if(k == len)
            all_strs.push_back(new_str);
        else{
            for(int i=k; i<len; i++){
                if(trace_matrix[k][i]){
                    new_str.push_back(s.substr(k,i-k+1));
                    recurison(s, trace_matrix, all_strs, new_str, i+1);
                    new_str.pop_back();
                }
            }
        }
    }
};
