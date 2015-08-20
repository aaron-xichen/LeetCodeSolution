#include "../solution.h"
class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        // trivial case
        if(len == 0 || len == 1)
            return 0;
        queue<int> q;
        q.push(0);
        vector<int> jump(len, -1);
        jump[0] = 0;
        while(!q.empty()){
            int idx = q.front();
            q.pop();
            int range = nums[idx];
            // cout<<idx<<", "<<range<<", "<<jump[idx]<<endl;
            for(int i=range; i>=1; i--){
                if(idx + i >= len - 1){
                    return jump[idx] + 1;
                }else if(-1 == jump[idx + i]){
                    jump[idx + i] = jump[idx] + 1;
                    q.push(idx + i);
                }
            }
        }
        return -1;
    }
};
