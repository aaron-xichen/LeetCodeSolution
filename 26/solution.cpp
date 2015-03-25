#include<iostream>
using namespace std;
class Solution{
    public:
        int removeDuplicates(int A[], int n){
            if(NULL == A || 0 == n) return 0;
            int p = 1;
            for(int i=1; i<n; i++){
                if(A[i-1] != A[i]){
                    A[p++] = A[i];
                }
            }
            return p;
        }
};
