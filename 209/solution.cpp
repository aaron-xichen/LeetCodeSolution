#include "../solution.h"
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int begin = 0;
        int len = nums.size();
        int sum = 0;
        int min_len = INT_MAX;
        for(int i=0; i<len; i++){
            sum += nums[i];
            while(begin < i && sum - nums[begin] >=s ){
                sum -= nums[begin];
                begin++;
            }
            if(sum >= s)
                min_len = min(min_len, i - begin + 1);
        }
        return min_len == INT_MAX ? 0 : min_len;
    }
};
