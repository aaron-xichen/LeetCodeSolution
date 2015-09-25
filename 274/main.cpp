#include "./solution.cpp"
int main(){
    int num[] = {100};
    vector<int> nums(num, num + sizeof(num)/ sizeof(num[0]));

    Solution sl = Solution();
    cout << sl.hIndex(nums) <<endl;
}
