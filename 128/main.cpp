#include "./solution.cpp"
int main(){
    int num[] = {100,4,200,1,3,2};
    int len = sizeof(num)/ sizeof(num[0]);
    vector<int> nums(num, num+len);
    Solution sl = Solution();
    cout<<sl.longestConsecutive(nums)<<endl;
}
