#include "../solution.h"
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0, three = 0;
        for(int i=0; i<(int)nums.size(); i++){
            three = two & nums[i];
            two = (two | (one & nums[i])) & ~three;
            one = (one | nums[i]) & ~three;
            // cout<<"two: " << two<<endl;
        }
        return one;
    }
};
