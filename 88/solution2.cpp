#include "../solution.h"
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = m + n - 1, i = m - 1, j = n - 1;
        while(j >=0)
            if(i < 0 || nums1[i] < nums2[j])
                nums1[index--] = nums2[j--];
            else nums1[index--] = nums1[i--];
    }
};
