#include "./solution.cpp"
int main(){
    int d[] ={3,3,5,0,0,3,1,4};
    vector<int> data(d, d+sizeof(d)/sizeof(int));
    solution sl = solution();
    int max_profit = sl.maxProfit(8,data);
    cout<<max_profit<<endl;
}
