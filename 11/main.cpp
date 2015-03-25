#include "solution.cpp"
int main(){
    vector<int> v;
    v.push_back(10);
    v.push_back(1);
    v.push_back(23);
    v.push_back(43);
    v.push_back(4);
    solution s = solution();
    int maxArea = s.maxArea(v);
    cout<<maxArea<<endl;
}
