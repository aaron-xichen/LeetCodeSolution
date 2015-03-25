#include<string>
#include<iostream>
using namespace std;
class Solution{
    public:
        int titleToNumber(string s){
            int value = 0;
            for(int i=0; i<(int)s.length();i++){
                value = 26*value + s[i]-'A' + 1;
            }
            return value;
        }
};
