#include "../solution.h"
class solution{
    public:
        vector<vector<int> > combine(int n, int k){
            vector<vector<int> > all;
            if(k>n) return all;
            vector<int> current;
            recursion(1, k, n, all, current);
            return all;
        }

        void recursion(int start, int counter, int n,
                vector<vector<int> > &all, vector<int> &current){
            if(0 == counter){
                all.push_back(current);
                return;
            }
            for(int i=start; i<=n; i++){
                current.push_back(i);
                recursion(i+1, counter-1, n, all, current);
                current.pop_back();
            }
        }
};
