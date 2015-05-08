#include "./solution.cpp"
int main(){
    int num[] = {1,3,5,6};
    vector<int> nums(num, num+sizeof(num)/sizeof(num[0]));
    Solution sl = Solution();
    cout<<sl.searchInsert(nums, 7)<<endl;
}
