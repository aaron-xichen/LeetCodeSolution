#include "../solution.h"
class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        if(len1 == 0 || len2 == 0)
            return "0";

        vector<int> ans(len1 + len2, 0);
        for(int i=0; i<len1; i++){
            int carry = 0;
            int n1 = num1[len1 - i - 1] - '0';
            for(int j=0; j<len2; j++){
                int n2 = num2[len2 - j -1] - '0';
                int idx = len1 + len2 - 1 - i - j;
                int sum = n1 * n2 + carry + ans[idx];
                ans[idx] =  sum % 10;
                carry = sum / 10;
            }
            ans[len1 - 1 - i] += carry;
        }

        int start = 0;
        while(start < len1 + len2 && ans[start] == 0)
            start++;

        if(start == len1 + len2)
            return "0";

        string result = "";
        while(start < len1 + len2){
            result += ans[start++] + '0';
        }
        return result;
    }
};
