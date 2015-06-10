#include "./solution.cpp"
int main(){
    int num[] = {1,1000000};
    int len = sizeof(num) / sizeof(num[0]);
    vector<int> nums(num, num+len);
    Solution sl = Solution();
    cout<<sl.maximumGap(nums)<<endl;
}
