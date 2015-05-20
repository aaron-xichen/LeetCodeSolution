#include "../solution.h"
class Solution {
public:
    string convertToTitle(int n) {
        string result = "";
        while(n){
            int r = n % 26;
            n = n / 26;
            if(r == 0){
                result = 'Z' + result;
                n--;
            }else{
                result = char(r + 'A' - 1) + result;
            }
        }
        return result;
    }
};
