#include "./solution2.cpp"
int main(){
    int num[] = {0,1};
    int len = sizeof(num)/sizeof(num[0]);
    vector<int> nums(num, num+len);
    Solution sl = Solution();
    cout<<sl.canJump(nums)<<endl;
}
