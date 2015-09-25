#include "../solution.h"
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        int h_index = 0;
        sort(citations.begin(), citations.end(),
                [](const int &num1, const int &num2){
                return num1 > num2;
                }
            );
        for(int i=0; i<len; i++){
            if(i + 1 >= citations[i])
                return max(i, citations[i]);
        }
        return len;
    }
};
