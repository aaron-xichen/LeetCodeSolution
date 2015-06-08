#include "../solution.h"
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();

        // initialize
        int trace[len2+1];
        for(int i=0; i<len2+1; i++){
            trace[i] = i;
        }

        for(int i=1; i<len1+1; i++){
            int pre = trace[0];
            int cur = -1;
            trace[0] = i;
            for(int j=1; j<len2+1; j++){
                cur = trace[j];
                char c1 = word1[i-1];
                char c2 = word2[j-1];
                trace[j] = min(trace[j-1], trace[j]) + 1;
                if(c1 == c2)
                    trace[j] = min(trace[j], pre);
                else{
                    trace[j] = min(trace[j], pre+1);
                }
                pre = cur;
            }
        }
        return trace[len2];
    }
};
