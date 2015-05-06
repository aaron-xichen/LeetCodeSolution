#include "./solution.cpp"
int main(){
    string tokens_array[] = {"0", "3", "/"};
    vector<string> tokens(tokens_array, tokens_array + sizeof(tokens_array)/sizeof(tokens_array[0]));
    Solution sl = Solution();
    int rvl = sl.evalRPN(tokens);
    cout<<rvl<<endl;

}
