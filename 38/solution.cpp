#include "../solution.h"
class solution{
    public:
        string countAndSay(int n){
            if(n <= 0) return "";
            string current_str = "1";
            for(int i=0; i<n-1; i++){
                current_str = parse(current_str);
                // cout<<current_str<<endl;
            }
            return current_str;
        }

        string parse(string str){
            int len = str.length();
            int count = 1;
            char last_char = str[0];
            string result = "";
            for(int i=1; i<len; i++){
                if(str[i] == last_char){
                    count++;
                }else{
                    result.append(1,(char)('0'+count-0));
                    result.append(1, last_char);
                    last_char = str[i];
                    count = 1;
                }
            }
            result.append(1,(char)('0'+count-0));
            result.append(1, str[len-1]);
            return result;
        }
};
