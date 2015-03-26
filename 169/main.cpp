#include "solution.cpp"
int main(){
    solution sl = solution();
    vector<int> s;
    s.push_back(3);
    s.push_back(3);
    s.push_back(4);
    // s.push_back(1);
    // s.push_back(1);
    int ele = sl.majorityElement(s);
    cout<<ele<<endl;
}
