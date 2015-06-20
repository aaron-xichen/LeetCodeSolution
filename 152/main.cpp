#include "./solution2.cpp"
int main(){
    int num[] = {0, -2, 0};
    int len = sizeof(num) / sizeof(num[0]);
    vector<int> nums(num, num+len);

    Solution sl = Solution();
    cout<<sl.maxProduct(nums)<<endl;
}
