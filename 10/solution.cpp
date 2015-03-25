#include<iostream>
using namespace std;
class Solution{
    public:
        bool isMatch(const char*s, const char *p){
            int idx1 = 0;
            int idx2 = 0;
            while(true){
                char ss = *(s+idx1);
                char pp = *(p+idx2);
                if('\0' == ss){
                    if(pp!='\0' && *(p+idx2+1) == '*'){
                        idx2 = idx2 + 2;
                        continue;
                    }else if(pp == '\0')
                        return true;
                    return false;
                }
                if('\0' == pp)
                    return false;
                if(ss==pp || pp=='.'){
                    idx1++;
                    if(*(p+idx2+1)!='*')
                        idx2++;
                }else{
                    if(*(p+idx2+1)!='*')
                        idx2++;
                    else
                        idx2 = idx2 + 2;
                }
            }
            return false;
        }
};
