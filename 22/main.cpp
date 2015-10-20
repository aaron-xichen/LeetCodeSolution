#include "./solution.cpp"
int main(){
    Solution sl = Solution();
    vector<string> solutions = sl.generateParenthesis(3);
    for(int i=0; i<(int)solutions.size(); i++){
        cout<<solutions[i]<<endl;
    }
}
