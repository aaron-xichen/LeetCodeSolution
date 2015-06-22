#include "../solution.h"
class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        vector<vector<int> > all_solution;
        for(int i=0; i<len-3; i++){
            if(i && nums[i-1] == nums[i]) continue;
            for(int j=i+1; j<len-2; j++){
                if(j != i+1 && nums[j-1] == nums[j]) continue;
                int left = j+1;
                int right = len-1;
                int remain = target - nums[i] - nums[j];
                while(true){
                    while(left != j+1 && left < len && nums[left-1] == nums[left])
                        left++;
                    while(right < len-1 && right > 0 && nums[right] == nums[right+1])
                        right--;
                    int sum = nums[left] + nums[right];
                    if(left >= right)
                        break;
                    else if(sum == remain){
                        vector<int> solution;
                        solution.push_back(nums[i]);
                        solution.push_back(nums[j]);
                        solution.push_back(nums[left++]);
                        solution.push_back(nums[right--]);
                        all_solution.push_back(solution);
                    }else if(sum < remain){
                        left++;
                    }else{
                        right--;
                    }
                }
            }
        }
        return all_solution;
    }
};
