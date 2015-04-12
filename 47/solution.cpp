#include "../solution.h"
class solution{
    public:
        vector<vector<int> > permuteUnique(vector<int> &num){
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
                if(i==n)
                    recursion(all, num, n+1);
                else if(!isDuplicate(num, n, i)){
                    swap(num, n, i);
                    recursion(all, num, n+1);
                    swap(num, n, i);
                }
            }
        }
        void swap(vector<int> &num, int idx1, int idx2){
            int tmp = num[idx1];
            num[idx1] = num[idx2];
            num[idx2] = tmp;
        }

        bool isDuplicate(vector<int> &num, int left, int right){
            for(int k=left; k<right; k++){
                if(num[k] == num[right])
                    return true;
            }
            return false;
        }
};
