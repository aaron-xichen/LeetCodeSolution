#include "./solution2.cpp"
int main(){
    int nums1[] = {4,5,6,0,0,0};
    int nums2[] = {1,2,3};
    int size1 = sizeof(nums1)/sizeof(nums1[0]);
    int size2 = sizeof(nums2)/sizeof(nums2[0]);
    vector<int> vec1(nums1, nums1+size1);
    vector<int> vec2(nums2, nums2+size2);
    Solution sl = Solution();
    size1 = 3;
    size2 = 3;
    sl.merge(vec1, size1, vec2, size2);
    for(int i=0; i<(int)vec1.size(); i++){
        cout<<vec1[i]<<" ";
    }
}
