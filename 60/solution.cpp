#include "../solution.h"
class Solution {
public:
    string getPermutation(int n, int k) {
        string digits = "";
        vector<int> perms(n+1, 1);
        for(int i=1; i<=n; i++){
            digits += to_string(i);
            perms[i] = perms[i-1] * i;
        }

        // cout<<digits<<endl;
        // for(int i=0; i<(int)perms.size(); i++)
            // cout<<perms[i]<<", ";
        // cout<<endl;

        string r = "";
        k--;
        for(int i=n; i>=1; i--){
            int q = k / perms[i-1];
            // cout<<"q:"<<q<<endl;
            r += digits[q];
            digits.erase(q, 1);

            int res = k % perms[i-1];
            // cout<<"res:"<<res<<endl;
            // if(res == 1){
                // r += digits;
                // break;
            // }
            k = res;
        }
        return r;
    }
};
