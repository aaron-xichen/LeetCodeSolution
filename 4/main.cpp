#include "./solution.cpp"
int main(){
    int num1[] = {};
    int num2[] = {2, 3};

    vector<int> nums1(num1, num1+sizeof(num1)/sizeof(num1[0]));
    vector<int> nums2(num2, num2+sizeof(num2)/sizeof(num2[0]));

    Solution sl = Solution();
    cout<<sl.findMedianSortedArrays(nums1, nums2);
}
