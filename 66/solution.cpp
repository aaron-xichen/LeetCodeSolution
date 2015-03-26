#include <iostream>
#include <vector>
using namespace std;
class solution{
    public:
        vector<int> plusOne(vector<int> &digits){
            int len = digits.size();
            bool flag = true;
            for(int i=len-1; i>=0; i--){
                if(flag){
                    digits[i] += 1;
                    flag = false;
                }
                if(digits[i] >= 10){
                    digits[i] = 0;
                    flag = true;
                }
                if(!flag)
                    break;
            }
            if(flag){
                digits.insert(digits.begin(), 1);
            }
            return digits;
        }
};
