#include "../solution.h"
class MinStack{
    int minValue;
    stack<int> s;
    stack<int> min_s;
    public:
        void push(int x){
            s.push(x);
            if(min_s.empty())
                min_s.push(x);
            else if(x <= getMin())
                min_s.push(x);
        }
        void pop(){
            if(top() == getMin())
                min_s.pop();
            s.pop();
        }
        int top(){
            return s.top();
        }
        int getMin(){
            return min_s.top();
        }
};
