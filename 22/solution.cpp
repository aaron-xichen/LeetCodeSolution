#include "../solution.h"
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string cur = "";
        vector<string> solutions;
        recursion(cur, solutions, n, n);
        return solutions;
    }

    void recursion(string cur, vector<string> &solutions, int left, int right){
        if(left > 0)
            recursion(cur + "(", solutions, left - 1, right);
        if(right > 0 && right > left)
            recursion(cur + ")", solutions, left, right - 1);
        if(left == 0 && right == 0)
            solutions.push_back(cur);
    }
};
