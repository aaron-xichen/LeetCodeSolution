#include "./solution.cpp"
int main(){
    int num[] = {0, 0, 4, 4};
    vector<int> nums(num, num + sizeof(num)/ sizeof(num[0]));

    Solution sl = Solution();
    cout << sl.hIndex(nums) <<endl;
}
