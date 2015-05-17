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

        // 0 represents unknown
        // 1 represents once been
        vector<vector<bool> > maps(len1+1, vector<bool>(len2+1, false));
        return recursion(maps, 0, 0, s1, s2, s3);
    }

    bool recursion(vector<vector<bool> > &maps, int i, int j, string &s1,
            string &s2, string &s3){
        if( i== (int)s1.length() && j == (int)s2.length())
            return true;

        // mark
        maps[i][j] = true;

        // down first
        bool is_ok = false;
        if(i+1 <= (int)s1.length() && !maps[i+1][j] && s1[i] == s3[i+j]){
            is_ok = recursion(maps, i+1, j, s1, s2, s3);
            if(is_ok)
                return true;
        }
        // right first
        if(j+1 <= (int)s2.length() && !maps[i][j+1] && s2[j] == s3[i+j]){
            is_ok = recursion(maps, i, j+1, s1, s2, s3);
            if(is_ok)
                return true;
        }
        return false;
    }
};
