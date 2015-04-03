#include "solution.cpp"
int main(){
    solution sl = solution();
    vector<vector<int> > all = sl.combine(10,2);
    for(int i=0; i<(int)all.size();i++){
        vector<int> ele = all[i];
        for(int j=0; j<(int)ele.size(); j++){
            cout<<ele[j]<<" ";
        }
        cout<<endl;
    }
}
