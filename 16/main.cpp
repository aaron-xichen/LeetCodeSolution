#include "./solution.cpp"
int main(){
    int num[] = {-1, 2, 1, -4};
    vector<int> nums(num, num + sizeof(num) / sizeof(num[0]));
    int target = 1;


    Solution sl = Solution();
    cout<<sl.threeSumClosest(nums, target)<<endl;
}
