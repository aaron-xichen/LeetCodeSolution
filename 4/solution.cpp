#include "../solution.h"
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int length1 = nums1.size();
        int length2 = nums2.size();
        int mid = (length1 + length2) / 2;
        double a = kth(nums1.data(), length1, nums2.data(), length2, mid+1);
        if((length1 + length2) % 2 == 0){
            double b = kth(nums1.data(), length1, nums2.data(), length2, mid);
            a = (a + b) / 2.0;
        }
        return a;
    }

    double kth(int nums1[], int m, int nums2[], int n, int k){
        if(m < n)
            return kth(nums2, n, nums1, m, k);
        if(n == 0)
            return nums1[k-1];
        if(k == 1)
            return min(nums1[0], nums2[0]);

        int j = min(n, k / 2);
        int i = k - j;
        if(nums1[i-1] > nums2[j-1])
            return kth(nums1, m, nums2+j, n-j, k-j);
        else
            return kth(nums1+i, m-i, nums2, n, k-i);
    }
};
