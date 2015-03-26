#include "solution.cpp"
int main(){
    solution sl = solution();
    vector<int> s;
    s.push_back(9);
    s.push_back(9);
    s.push_back(9);
    s.push_back(9);
    vector<int> p =sl.plusOne(s);
    for(int i=0; i<(int)p.size(); i++){
        cout<<p[i]<<" ";
    }

}
