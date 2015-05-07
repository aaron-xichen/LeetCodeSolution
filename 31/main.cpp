#include "./solution.cpp"
int main(){
    int num[] = {1,5,1};
    int len = sizeof(num)/sizeof(num[0]);
    vector<int> nums(num, num+len);
    Solution sl = Solution();
    sl.nextPermutation(nums);
    for(int i=0; i<len; i++){
        cout<<nums[i]<<" ";
    }
}

