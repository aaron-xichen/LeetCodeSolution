#include "./solution.cpp"
int main(){
    int num[] = {1, 2, 2, 2, 1, 1, 0};
    // int num[] = {0};
    int len = sizeof(num) / sizeof(num[0]);
    vector<int> nums(num, num + len);

    Solution sl = Solution();
    int ans = sl.singleNumber(nums);
    cout<<"ans: " << ans << endl;
}
