#include "./solution.cpp"
int main(){
    int num[] = {1, 1, 1, 2, 2, 3};
    vector<int> nums(num, num + sizeof(num)/sizeof(num[0]));

    Solution sl = Solution();
    int length = sl.removeDuplicates(nums);
    cout<<length<<endl;
    for(int i=0; i<length; i++){
        cout<<nums[i]<<" ";
    }
}
