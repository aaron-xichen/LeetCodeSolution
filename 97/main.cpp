#include "./solution2.cpp"
int main(){
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    Solution sl = Solution();
    cout<<sl.isInterleave(s1, s2, s3)<<endl;
}
