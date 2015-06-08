#include "../solution.h"
class Solution {
public:
    string convert(string s, int numRows) {
        // trivial case
        if(numRows == 1)
            return s;
        int str_len = s.length();
        int period = 2*(numRows-1);
        string result = "";
        for(int i=0; i<numRows; i++){
            int begin = i;
            int interval = period - 2*i;
            if(interval == 0)
                interval = period;
            while(begin < str_len){
                result += s[begin];
                begin += interval;
                if(period != interval)
                    interval = period - interval;
            }
        }
        return result;
    }
};
