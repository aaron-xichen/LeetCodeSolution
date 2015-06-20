#include "./solution.cpp"
int main(){
    map<int,int> m;
    m.insert(pair<int,int>(1,4));
    m.insert(pair<int,int>(1,5));
    Solution sl = Solution();
    vector<int> result = sl.merge(m);
    for(auto it = m.begin(); it!=m.end(); ++it){
        cout<<it->first<<":"<<it->second<<endl;
    }
}
