#include "./solution.cpp"
int main(){
    int num[] = {1, 0, -1, 0, -2, 2};
    int target = 0;
    int len = sizeof(num) / sizeof(num[0]);
    vector<int> nums(num, num+len);

    Solution sl = Solution();
    vector<vector<int> > all_solution = sl.fourSum(nums, target);
    for(int i=0; i<(int)all_solution.size(); i++){
        for(int j=0; j<(int)all_solution[0].size(); j++){
            cout<<all_solution[i][j]<<" ";
        }
        cout<<endl;
    }
}
