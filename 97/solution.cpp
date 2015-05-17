#include "../solution.h"
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        //trivial case
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        if(len1 + len2 != len3)
            return false;

        bool maps[len1+1][len2+1];
        for(int i=0; i<len1+1; i++){
            for(int j=0; j<len2+1; j++){
                maps[i][j] = false;
            }
        }
        maps[0][0] = true;
        for(int i=1; i<len1+1; i++){
            if(maps[i-1][0] && s1[i-1] == s3[i-1])
                maps[i][0] = true;
        }
        for(int j=1; j<len2+1; j++){
            if(maps[0][j-1] && s2[j-1] == s3[j-1])
                maps[0][j] = true;
        }

        for(int i=1; i<len1+1; i++){
            for(int j=1; j<len2+1; j++){
                if(maps[i-1][j] && s1[i-1] == s3[i+j-1])
                    maps[i][j] = true;
                if(maps[i][j-1] && s2[j-1] == s3[i+j-1])
                    maps[i][j] = true;
            }
        }

        // for(int i=0; i<len1+1; i++){
            // for(int j=0; j<len2+1; j++){
                // cout<<maps[i][j]<<" ";
            // }
            // cout<<endl;
        // }
        return maps[len1][len2];
    }
};
