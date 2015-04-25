#include "../solution.h"
class Solution{
    public:
        vector<vector<int> > subsets(vector<int> &S){
            int len = S.size();
            vector<vector<int> > subsets;

            // trivial case
            if(0 == len)
                return subsets;

            // initialization
            sort(S.begin(), S.end());
            vector<int> base;
            subsets.push_back(base);
            for(int i=0; i<len; i++){
                int ele = S[i];
                int size = subsets.size();
                for(int j=0; j<size; j++){
                    subsets.push_back(subsets[j]);
                    subsets[size+j].push_back(ele);
                }
            }
            return subsets;
        }
};
