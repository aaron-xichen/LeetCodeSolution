#include "../solution.h"
class Solution{
    public:
        vector<vector<int> > subsetsWithDup(vector<int> &S){
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
                    if(subsets[j].empty()){
                        subsets.push_back(subsets[j]);
                        int idx = subsets.size();
                        subsets[idx-1].push_back(ele);
                        continue;
                    }

                    int l = subsets[j].size();
                    if(subsets[j][l-1] == ele){
                        subsets[j].push_back(ele);
                    }else{
                        subsets.push_back(subsets[j]);
                        int idx = subsets.size();
                        subsets[idx-1].push_back(ele);
                    }
                }
            }
            return subsets;
        }
};
