#include "./solution.cpp"
int main(){
    int target = 10;
    int num[] = {4, 5, 6, 7, 0, 1, 2, 3};
    int len = sizeof(num) / sizeof(num[0]);
    vector<int> nums(num, num+len);

    Solution sl = Solution();
    cout<<sl.search(nums, target)<<endl;
}
