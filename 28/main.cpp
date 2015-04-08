#include "./solution.cpp"
int main(){
    solution sl = solution();
    char haystack[] = "mississippi";
    char needle[] = "issip";
    int idx = sl.strStr(haystack, needle);
    cout<<idx<<endl;
}
