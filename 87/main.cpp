#include "./solution.cpp"
int main(){
    Solution sl = Solution();
    // string s1 = "abcdefghijklmnopq";
    // string s2 = "efghijklmnopqcadb";
    string s1 = "xstjzkfpkggnhjzkpfjoguxvkbuopi";
    string s2 = "xbouipkvxugojfpkzjhnggkpfkzjts";
    cout<<sl.isScramble(s1, s2)<<endl;
}
