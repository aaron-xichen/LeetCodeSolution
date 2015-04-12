#include "./solution.cpp"
int main(){
    int nums[] = {1,1,2,2};
    vector<int> num(nums, nums+sizeof(nums)/sizeof(int));
    solution sl = solution();
    vector<vector<int> > all = sl.permuteUnique(num);

    for(int i=0; i<(int)all.size(); i++){
        for(int j=0; j<(int)all[0].size(); j++){
            cout<<all[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"size:"<<all.size()<<endl;
}
