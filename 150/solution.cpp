#include "../solution.h"
class Solution{
    public:
        int evalRPN(vector<string> &tokens){
            // trivial case
            if(tokens.empty())
                return 0;
            else if(tokens.size() == 1)
                return stoi(tokens[0]);

            stack<int> operands;
            operands.push(stoi(tokens[0]));
            int operands_cache = stoi(tokens[1]);
            for(int i=2; i<(int)tokens.size(); i++){
                string op = tokens[i];
                if(op != "+" && op != "-" && op !="*" && op != "/"){
                    operands.push(operands_cache);
                    operands_cache = stoi(op);
                }else{
                    int operand = operands.top();
                    operands.pop();
                    if(op == "+")
                        operands_cache = operand + operands_cache;
                    else if(op == "-")
                        operands_cache = operand - operands_cache;
                    else if(op == "*")
                        operands_cache = operand * operands_cache;
                    else if(op == "/")
                        operands_cache = operand / operands_cache;
                    else
                        cout<<"fatal error"<<endl;
                }
            }
            return operands_cache;
        }
};
