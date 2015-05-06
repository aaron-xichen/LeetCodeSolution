#include "../solution.h"
class Solution{
    public:
        bool isNumber(string s){
            int len = s.length();
            // trivial case
            if(0 == len)
                return false;

            // finity state machine
            int state = 0;
            for(int i=0; i<len; i++){
                char c = s[i];
                switch(state){
                    case 0:{
                               if(c == ' ')
                                   state = 0;
                               else if(c == '.')
                                   state = 3;
                               else if(c >= '0' && c <='9')
                                   state = 1;
                               else if(c == '-' || c == '+')
                                   state = 8;
                               else
                                   return false;
                               break;
                           }
                    case 1:{
                               if(c >= '0' && c <='9')
                                   state = 1;
                               else if (c == '.')
                                   state = 2;
                               else if (c == 'e')
                                   state = 5;
                               else if (c == ' ')
                                   state = 7;
                               else
                                   return false;
                               break;
                           }
                    case 2:{
                               if(c >= '0' && c <= '9')
                                   state = 4;
                               else if(c == 'e')
                                   state = 5;
                               else if(c == ' ')
                                   state = 7;
                               else
                                   return false;
                               break;
                           }
                    case 3:{
                               if(c >= '0' && c <= '9')
                                   state = 4;
                               else
                                   return false;
                               break;
                           }
                    case 4:{
                               if(c >= '0' && c <= '9')
                                   state = 4;
                               else if(c == 'e')
                                   state = 5;
                               else if(c == ' ')
                                   state = 7;
                               else
                                   return false;
                               break;
                           }
                    case 5:{
                               if(c >= '0' && c <='9')
                                   state = 6;
                               else if(c == '-' || c == '+')
                                   state = 9;
                               else
                                   return false;
                               break;
                           }
                    case 6:{
                               if(c >= '0' && c <= '9')
                                   state = 6;
                               else if(c == ' ')
                                   state = 7;
                               else
                                   return false;
                               break;
                           }
                    case 7:{
                               if(c != ' ')
                                   return false;
                               break;
                           }
                    case 8:{
                               if(c >= '0' && c <= '9')
                                   state = 1;
                               else if(c == '.')
                                   state = 3;
                               else
                                   return false;
                               break;
                           }
                    case 9:{
                               if(c >= '0' && c <= '9')
                                   state = 6;
                               else
                                   return false;
                               break;
                           }
                    default:{
                                return false;
                            }
                }
            }
            if(state == 0 || state == 3 || state == 5 || state == 8 || state == 9)
                return false;
            else
                return true;
        }
};
