#include "./solution2.cpp"
int main(){
    int target = 3;
    int num[] = {1, 3, 1, 1, 1};
    int len = sizeof(num) / sizeof(num[0]);
    vector<int> nums(num, num+len);

    Solution sl = Solution();
    cout<<sl.search(nums, target)<<endl;
}
