#include "./solution.cpp"
int main(){
    int num[] = {-1, 2147483647};
    int k = 1;
    int t = 2147483647;
    vector<int> nums(num, num+sizeof(num)/sizeof(num[0]));

    Solution sl = Solution();
    cout<<sl.containsNearbyAlmostDuplicate(nums, k, t);
}
