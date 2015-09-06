#include "./solution2.cpp"
int main(){
    int num[] = {3, 2, 4};
    vector<int> nums(num, num + sizeof(num) / sizeof(num[0]));
    int target = 6;

    Solution sl = Solution();
    vector<int> ans=sl.twoSum(nums, target);
    cout<<ans[0]<<", "<<ans[1]<<endl;
}
