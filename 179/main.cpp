#include "./solution2.cpp"
int main(){
    // int total_len = 3;
    // int offset = (int)pow(10, total_len);
    // int part1 = INT_MAX / offset;
    // int part2 = INT_MAX - part1*offset;

    // cout<<INT_MAX<<endl;
    // cout<<part1<<endl;
    // cout<<part2<<endl;

    int num[] = {30, 34, 5, 9, 3};
    int len = sizeof(num) / sizeof(num[0]);
    vector<int> nums(num, num+len);

    Solution sl = Solution();
    cout<<sl.largestNumber(nums)<<endl;
}
