#include "../solution.h"
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n <= 0)
            return false;
        vector<int> trace(n);
        trace[0] = 1;
        int ptr2=0, ptr3=0, ptr5=0;
        for(int i=1; i<n; i++){
            int min_value = min(trace[ptr2]*2, min(trace[ptr3]*3, trace[ptr5]*5));
            if(trace[ptr2]*2 == min_value) ptr2++;
            if(trace[ptr3]*3 == min_value) ptr3++;
            if(trace[ptr5]*5 == min_value) ptr5++;
            trace[i] = min_value;
        }
        return trace[n-1];
    }
};
