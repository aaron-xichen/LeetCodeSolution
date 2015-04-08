#include "../solution.h"
class solution{
    public:
        string addBinary(string a, string b){
            string result ="";
            int len1 = a.length();
            int len2 = b.length();
            if(len1 == 0) return b;
            if(len2 == 0) return a;
            int flag = false;
            int pt_str1 = len1-1;
            int pt_str2 = len2-1;
            while(pt_str1>=0 || pt_str2>=0){
                char sum = '0';
                if(pt_str1 >= 0 ){
                    sum += a[pt_str1] - '0';
                    pt_str1--;
                }
                if(pt_str2 >=0 ){
                    sum += b[pt_str2] - '0';
                    pt_str2--;
                }
                if(flag){
                    sum += 1;
                    flag = false;
                }
                if(sum > '1'){
                    sum -= 2;
                    flag = true;
                }
                result = sum + result;
            }
            if(flag){
                result = "1" + result;
            }
            return result;
        }
};
