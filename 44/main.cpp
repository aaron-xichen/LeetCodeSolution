#include "solution.cpp"
int main(){
    const char *s ="aa";
    const char *p = "?*";
    solution sl = solution();
    cout<<sl.isMatch(s, p);
}
