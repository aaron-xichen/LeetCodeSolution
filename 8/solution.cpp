#include "../solution.h"
class Solution{
    public:
        int myAtoi(string str){
            int state = 1;
            int len = str.size();
            int val = 0;
            int is_overflow = false;
            int is_negative = false;
            for(int i=0; i<len; i++){
                char c = str[i];
                bool is_stop = false;
                switch(state){
                    case 1:
                        if(c == '+' || c == '-'){
                            is_negative = (c == '-');
                            state = 3;
                        }else if(c >= '0' && c <= '9'){
                            state = 2;
                            val = c - '0';
                        }else if(c == ' ')
                            state = 1;
                        else
                            is_stop = true;
                        break;
                    case 2:
                        if(c >= '0' && c <= '9'){
                            if(!is_overflow){
                                int increase = c - '0';
                                int new_val = 10 * val + increase;
                                if((new_val - increase) / 10 != val)
                                    is_overflow = true;
                                else if(val == 214748364 && increase >= 8)
                                    is_overflow = true;
                                else
                                    val = new_val;
                            }
                            state = 2;
                        }else
                            is_stop = true;
                        break;
                    case 3:
                        if(c >= '0' && c <= '9'){
                            val = c - '0';
                            state = 2;
                        }else
                            is_stop = true;
                        break;
                    default:
                        is_stop = true;
                }
                if(is_stop)
                    break;
            }

            cout<<"is_overflow:"<<is_overflow<<endl;
            cout<<"is_negative:"<<is_negative<<endl;
            if(state == 1 || state == 3 || state == 5)
                return 0;
            if(is_overflow && is_negative)
                return INT_MIN;
            else if(is_overflow && !is_negative)
                return INT_MAX;
            else if(is_negative)
                return -val;
            else
                return val;
        }
};
