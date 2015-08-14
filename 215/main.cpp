#include "./solution.cpp"
int main(){
    int num[] = {3, 2, 1, 5, 6, 4};
    vector<int> nums(num, num+sizeof(num) / sizeof(num[0]));


    Solution sl = Solution();
    cout<<sl.findKthLargest(nums, 2)<<endl;
}
