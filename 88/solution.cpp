#include "../solution.h"
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // trivial case
        if(n == 0)
            return;
        if(m == 0){
            nums1 = nums2;
            return;
        }

        int total = m + n;
        int i=0, j=0;
        while(j<n && m >0){
            if(nums1[i++] >= nums2[j]){
                nums1.insert(nums1.begin() + i - 1, nums2[j++]);
            }else
                m--;
        }
        if(m == 0)
            for(int l=j; l<n;)
                nums1[i++] = nums2[l++];

        int len = nums1.size();
        if(len > total)
            for(int k=0; k<len-total; k++)
                nums1.pop_back();
    }
};
