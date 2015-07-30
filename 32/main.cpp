#include "./solution2.cpp"
int main(){
    string s = "()(()(((((())())((()))(()((())()(()()(()((()))()))))())))))())()())))(()()()())((()()()))()(()(()))())(((()))())(()((()))(()(()))()";
    Solution sl = Solution();
    cout<<sl.longestValidParentheses(s)<<endl;
}
