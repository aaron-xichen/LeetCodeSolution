#include "../solution.h"
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int len = s.length();
        vector<string> ans;
        if(len < 10)
            return  ans;

        int hash = 0x0;
        for(int i=0; i<9; i++){
            hash = (hash << 3) | (s[i] & 0x7);
        }

        unordered_map<int, int> m;
        for(int i=9; i<len; i++){
            char c = s[i];
            hash = ((hash << 3) & 0x3fffffff) | (c & 0x7);
            // cout<<hash<<endl;
            m[hash]++;
        }

        // cout<<"size: " << m.size() <<endl;
        for(auto it=m.begin(); it!=m.end(); ++it){
            if(it->second >= 2)
                ans.push_back(i2s(it->first));
        }
        return ans;
    }

    string i2s(int hash){
        // cout<<"!"<<endl;
        string str;
        while(hash){
            int c = hash & 7;
            if(c == 1)
                str = 'A' + str;
            else if(c == 4)
                str = 'T' + str;
            else if(c == 3)
                str = 'C' + str;
            else
                str = 'G' + str;
            hash  = hash >> 3;
        }
        return str;
    }
};
