#include "../solution.h"
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int> ans;
        if(len <= 1)
            return ans;

        int left = 0, right = len -1 ;
        vector<int> ori = nums;
        sort(nums.begin(), nums.end());
        while(left < right){
            if(nums[left] + nums[right] < target)
                left++;
            else if(nums[left] + nums[right] > target)
                right--;
            else{
                ans.push_back(nums[left]);
                ans.push_back(nums[right]);
                break;
            }
        }

        for(int i=0; i<len; i++){
            if(ori[i] == ans[0]){
                ans[0] = i + 1;
                break;
            }
        }
        for(int i=len-1; i>=0; i--){
            if(ori[i] == ans[1]){
                ans[1] = i + 1;
                break;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
