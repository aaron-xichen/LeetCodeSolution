#include "./solution.cpp"
int main(){
    int num[] = {0, 1, 0, 3, 12};
    int size = sizeof(num) / sizeof(num[0]);
    vector<int> nums(num, num + size);
    Solution sl = Solution();
    sl.moveZeroes(nums);

    for(int i=0; i<size; i++)
        cout<<nums[i]<<" ";
}
