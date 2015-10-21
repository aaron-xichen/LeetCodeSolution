#include "./solution2.cpp"
int main(){
    int num[] = {1, 2, 2, 2, 1, 0};
    int len = sizeof(num) / sizeof(num[0]);
    vector<int> nums(num, num + len);

    Solution sl = Solution();
    sl.sortColors(nums);
    for(int i=0; i<(int)nums.size(); i++){
        cout << nums[i] << " ";
    }
}
