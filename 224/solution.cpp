#include "../solution.h"
// wrong
class Solution {
public:
    int calculate(string s) {
        stack<char> operators;
        stack<int> operands;
        int len = s.length();
        int idx = 0;
        while(true){
            if(!operators.empty()){
                if((operators.top() == '+' || operators.top() == '-') &&
                        operands.size() >= 2){
                    int op2 = operands.top();
                    operands.pop();
                    int op1 = operands.top();
                    operands.pop();
                    char optr = operators.top();
                    operators.pop();
                    int ans;
                    // cout<<op1<<optr<<op2<<endl;
                    if(optr == '+')
                        ans = op1 + op2;
                    else
                        ans = op1 - op2;
                    operands.push(ans);
                    continue;
                }else if(operators.top() == ')'){
                    operators.pop();
                    operators.pop();
                    continue;
                }
            }

            if(idx >= len)
                break;

            if(s[idx] == ' '){
                idx++;
                continue;
            }

            int end = idx;
            while(end < len && s[end] >= '0' && s[end] <= '9')
                end++;

            if(end - idx + 1 == 1)
                operators.push(s[idx++]);
            else{
                operands.push(stoi(s.substr(idx, end - idx)));
                idx = end;
            }
        }
        return operands.top();
    }
};
