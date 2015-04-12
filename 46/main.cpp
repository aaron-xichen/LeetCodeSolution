#include "./solution.cpp"
int main(){
    int nums[] = {1,2,3};
    vector<int> num(nums, nums+sizeof(nums)/sizeof(int));
    solution sl = solution();
    vector<vector<int> > all = sl.permute(num);

    for(int i=0; i<(int)all.size(); i++){
        for(int j=0; j<(int)all[0].size(); j++){
            cout<<all[i][j]<<" ";
        }
        cout<<endl;
    }
}
