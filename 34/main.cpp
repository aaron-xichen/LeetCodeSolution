#include "./solution.cpp"
int main(){
    int num[] = {1};
    vector<int> nums(num, num + sizeof(num) / sizeof(num[0]));

    Solution sl = Solution();
    vector<int> idxs = sl.searchRange(nums, 1);
    cout<<idxs[0] << ", " << idxs[1];
}
