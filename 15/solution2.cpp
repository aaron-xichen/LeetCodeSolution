#include "../solution.h"
class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > all_solutions;
        int len = nums.size();
        vector<int> new_solution;
        for(int i=0; i<len; i++){
            if(i>0 && nums[i-1] == nums[i]) continue;
            int left = i+1;
            int right = len-1;
            int target = -nums[i];
            new_solution.push_back(nums[i]);
            while(true){
                while(left!=i+1 && nums[left-1]==nums[left])
                    left++;
                while(right<len-1 && nums[right+1] == nums[right])
                    right--;
                if(left >= right) break;
                if(nums[left] + nums[right] == target){
                    new_solution.push_back(nums[left]);
                    new_solution.push_back(nums[right]);
                    all_solutions.push_back(new_solution);
                    new_solution.pop_back();
                    new_solution.pop_back();
                    left++;
                    right--;
                }else if(nums[left] + nums[right] > target){
                    right--;
                }else
                    left++;
            }
            new_solution.pop_back();
        }
        return all_solutions;
    }
};
