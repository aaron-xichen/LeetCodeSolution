#include "../solution.h"
class solution{
    public:
        vector<vector<int> > permute(vector<int> &num){
            vector<vector<int> > all;
            if(0 == num.size()) return all;
            recursion(all, num, 0);
            return all;
        }

        void recursion(vector<vector<int> > &all, vector<int> &num, int n){
            if(n == (int)num.size()-1){
                all.push_back(num);
                return;
            }
            for(int i=n; i<(int)num.size(); i++){
                swap(num, n, i);
                recursion(all, num, n+1);
                swap(num, n, i);
            }
        }
        void swap(vector<int> &num, int idx1, int idx2){
            int tmp = num[idx1];
            num[idx1] = num[idx2];
            num[idx2] = tmp;
        }
};
