#include "./solution3.cpp"
int main(){
    int num[] = {1,2,3};
    vector<int> nums(num, num+sizeof(num) / sizeof(num[0]));

    Solution sl = Solution();
    cout<<sl.jump(nums)<<endl;
}
