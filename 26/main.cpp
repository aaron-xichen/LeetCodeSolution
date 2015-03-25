#include "solution.cpp"
int main(){
    int A[]={0,0,1,1,2,2,2,2,4,4,5,6,7};
    Solution solution = Solution();
    int len = solution.removeDuplicates(A, sizeof(A)/4);
    for(int i=0; i<len; i++){
        cout<<A[i]<<" ";
    }
    return 0;
}
