#include "../solution.h"
class Solution {
public:
    int getValue(char c) {
            switch (c) {
                case 'I':   return 1;
                case 'V':   return 5;
                case 'X':   return 10;
                case 'L':   return 50;
                case 'C':   return 100;
                case 'D':   return 500;
                case 'M':   return 1000;
                default:    return 0;
            }
        }
    int romanToInt(string s) {
        // trivial case
        if(s.empty())
            return 0;
        else if(1 == s.length()){
            return getValue(s[0]);
        }

        int previous_value = getValue(s[0]);
        int value = previous_value;
        for(int i=1; i<(int)s.length(); i++){
            int current_value = getValue(s[i]);
            if(current_value <=  previous_value)
                value += current_value;
            else
                value += current_value - 2 * previous_value;
            previous_value = current_value;
        }
        return value;
    }
};
