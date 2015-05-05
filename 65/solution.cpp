#include "../solution.h"
class Solution{
    public:
        bool isNumber(string s){
            int len  = s.length();
            // trivial case
            if (0 == len)
                return false;

            // strip
            int start=0, end=len-1;
            while(start <= end){
                if(s[start] == ' ')
                    start++;
                else if(s[end] == ' ')
                    end--;
                else
                    break;
            }

            // remove minus op. at the begin
            if(s[start] == '-' || s[start] == '+')
                start++;

            bool hasDecimalPoint = false;
            // remove decimal point at the begin
            if(s[start] == '.'){
                start++;
                hasDecimalPoint = true;
            }

            if(start > end)
                return false;

            // state machine
            int state = 0;
            for(int i=start; i<=end; i++){
                char c = s[i];
                switch(state){
                    case 0:{
                               if(c >= '0' && c <='9')
                                   state = 1;
                               else if (c == '.' && !hasDecimalPoint)
                                   state = 2;
                               else
                                   return false;
                               break;
                           }
                    case 1:{
                               if(c == '.' && !hasDecimalPoint)
                                   state = 2;
                               else if(c == 'e')
                                   state = 4;
                               else if(c >= '0' && c <= '9')
                                   state = 1;
                               else
                                   return false;
                               break;

                           }
                    case 2:{
                               if(c >= '0' && c <= '9')
                                   state = 3;
                               else if(c == 'e')
                                   state = 4;
                               else
                                   return false;
                               break;
                           }
                    case 3:{
                               if(c == 'e')
                                   state = 4;
                               else if(c >= '0' && c <='9')
                                   state = 3;
                               else
                                   return false;
                               break;
                           }
                    case 4:{
                               if( c >= '0' && c <= '9')
                                   state = 6;
                               else if(c == '-' || c == '+')
                                   state = 5;
                               else
                                   return false;
                               break;
                           }
                    case 5:{
                               if( c >= '0' && c <= '9')
                                   state = 6;
                               else
                                   return false;
                           }
                    case 6:{
                               if(c < '0' || c > '9')
                                   return false;
                               break;
                           }
                    default:
                           return false;
                }
            }
            if(state == 4 || state == 5)
                return false;
            else
                return true;
        }

};

