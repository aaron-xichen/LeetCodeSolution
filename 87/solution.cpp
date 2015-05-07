#include "../solution.h"
class Solution{
    public:
        bool isScramble(string s1, string s2){
            // cout<<s1<<" "<<s2<<endl;
            if(s1.length() != s2.length())
                return false;

            if(1 == s1.length()){
                return s1[0] == s2[0];
            }else if(2 == s1.length()){
                return (s1[0] == s2[0] && s1[1] == s2[1]) ||
                    (s1[0] == s2[1] && s1[1] == s2[0]);
            }

            int counts[26];
            memset(counts, 0, 26*sizeof(counts[0]));

            for(int i=0; i<(int)s1.length(); i++){
                counts[s1[i]-'a']++;
            }
            for(int i=0; i<(int)s2.length(); i++){
                counts[s2[i]-'a']--;
            }

            // check
            for(int i=0; i<26; i++){
                if(0 != counts[i]){
                    // cout<<char(i+'a')<<endl;
                    return false;
                }
            }

            // recursive
            for(int i=1; i<(int)s1.length(); i++){
                if(isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                    isScramble(s1.substr(i, s1.length()-i), s2.substr(i, s2.length()-i)))
                    return true;

                if(isScramble(s1.substr(0, i), s2.substr(s2.length()-i, i)) &&
                    isScramble(s1.substr(i, s1.length()-i), s2.substr(0, s2.length()-i)))
                    return true;
            }

            return false;
        }
};
