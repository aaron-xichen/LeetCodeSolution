#include<iostream>
using namespace std;
class Solution{
    public:
        int trailingZeros(int n){
            if(n<5) return 0;
            else return n/5 + trailingZeros(n/5);
        }
};
