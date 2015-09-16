#include "../solution.h"
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";
        unordered_map<int, string> m;
        string tmp = "0";
        for(int i=0; i<=9; i++){
            m.insert(pair<int, string>(i, tmp));
            tmp = add(tmp, num1);
            // cout<<"i: " << i << ", val: " << tmp << endl;
        }
        string sum = "0";
        int len2 = num2.size();
        for(int i=len2-1; i>=0; i--){
            int digit = num2[i] - '0';
            string str = m.find(digit)->second + string(len2 - 1 - i, '0');
            sum = add(sum, str);
        }
        return sum;
    }

    string add(string num1, string num2){
        int len1 = num1.size();
        int len2 = num2.size();
        int len = max(len1, len2);
        char sum[len + 1];
        sum[len] = '\0';
        bool carry = false;
        for(int i=0; i<len; i++){
            int s = 0;
            if(carry){
                s += 1;
                carry = false;
            }
            s += len1 - 1 - i >= 0 ? (num1[len1 - 1 - i] - '0') : 0;
            s += len2 - 1 - i >= 0 ? (num2[len2 - 1 - i] - '0') : 0;
            if(s >= 10){
                carry = true;
                s = s % 10;
            }
            // cout<<"pos: " << len - 1 - i << ", val: " << s <<endl;
            sum[len - 1 - i] = s + '0';
        }
        // string ans = string(sum);
        string ans = carry ? "1" + string(sum) : string(sum);
        // cout<<"str: " << ans << ", len: " << ans.size() <<endl;
        return ans;
    }
};
