#include "../solution.h"
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        int left = 0, right = len - 1;
        // int h_index = 0;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(len - mid < citations[mid]){
                // h_index = max(h_index, len - mid);
                right = mid -1;
            }else if(len - mid > citations[mid]){
                // h_index = max(h_index, citations[mid]);
                left = mid + 1;
            }else
                return citations[mid];
        }
        // return h_index;
        return len - (right + 1);
    }
};
