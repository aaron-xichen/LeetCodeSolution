#include "./solution.cpp"
int main(){
    int num[] = {80, 60, 30 ,40, 20 ,10};
    int len = sizeof(num) / sizeof(num[0]);
    vector<int> nums(num, num+len);

    Solution sl = Solution();
    vector<int> result = sl.max_bitonic_seq(nums);
    for(int i=0; i<(int)result.size(); i++){
        cout<<result[i]<<" ";
    }
}
