#include "../solution.h"
class Solution {
public:
    int calculate(string s) {
        stack<char> operators;
        stack<int> operands;
        int len = s.length();
        int idx = 0;
        while(idx < len){
            if(s[idx] == ' '){
                idx++;
                continue;
            }

            int end = idx;
            while(end < len && s[end] >= '0' && s[end] <= '9')
                end++;

            if(end - idx + 1 == 1){
                char optr = s[idx++];
                // cout<<"optr: "<<optr<<endl;
                if(optr == ')'){
                    operators.pop();
                    simplify(operators, operands);
                }else
                    operators.push(optr);
            }else{
                int new_num = stoi(s.substr(idx, end - idx));
                // cout<<"operands: " << new_num<< endl;
                operands.push(new_num);
                simplify(operators, operands);
                idx = end;
            }
        }
        simplify(operators, operands);
        return operands.top();
    }

    void simplify(stack<char> &operators, stack<int> &operands){
        // if(!operators.empty()){
            // cout<<operators.top()<<endl;
        // }
        while(!operators.empty() &&
                (operators.top() == '+' || operators.top() == '-') &&
                operands.size() >= 2){
            // cout<<"sim: " << operators.size()<<", "<<operands.size()<<endl;
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
            // cout<<"sim2: " << operators.size()<<", "<<operands.size()<<endl;
        }
    }
};
