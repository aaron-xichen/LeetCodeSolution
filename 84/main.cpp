#include "./solution.cpp"
int main(){
    int num[] = {2, 1, 5, 6, 2, 3};
    int len = sizeof(num)/ sizeof(num[0]);
    vector<int> nums(num, num+len);

    Solution sl = Solution();
    cout<<sl.largestRectangleArea(nums)<<endl;
}
