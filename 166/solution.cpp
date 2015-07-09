#include "../solution.h"
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        int64_t n = numerator;
        int64_t d = denominator;
        string result;
        if((n>0 && d<0) || (n<0 && d>0)){
            result += "-";
        }
        n = abs(n);
        d = abs(d);

        result += to_string(n / d);

        if(n % d == 0) return result;

        result += ".";

        unordered_map<int, int> m;

        for(int64_t r = n % d; r; r %= d){

            if(m.find(r) != m.end()){
                int old_pos = m.find(r)->second;
                result.insert(old_pos, "(");
                result += ")";
                break;
            }

            m.insert(pair<int,int>(r,result.length()));
            r *= 10;
            result += to_string(r / d);
        }
        return result;
    }
};
