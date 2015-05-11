#include "./solution.cpp"
int main(){
    Solution sl = Solution();
    cout<<sl.myAtoi("123")<<endl;
    cout<<sl.myAtoi("123e")<<endl;
    cout<<sl.myAtoi("+123e")<<endl;
    cout<<sl.myAtoi("  +123e")<<endl;
    cout<<sl.myAtoi("   +12312415323534e")<<endl;
    cout<<sl.myAtoi("   -12312415323534e")<<endl;
    cout<<sl.myAtoi("  -0012a42")<<endl;
    cout<<sl.myAtoi("2147483648")<<endl;
}
