#include "./solution.cpp"
int main(){
    Solution sl = Solution();
    for(int i=1; i<=6; i++)
        cout<<sl.getPermutation(3, i)<<endl;
}
