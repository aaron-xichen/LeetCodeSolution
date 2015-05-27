#include "./solution.cpp"
int main(){
    int num[] = {1,2,0};
    int length = sizeof(num)/sizeof(num[0]);
    vector<int> nums(num, num+length);
    Solution sl = Solution();
    cout<<sl.firstMissingPositive(nums)<<endl;
}
