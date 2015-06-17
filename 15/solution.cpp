#include "../solution.h"
class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > all_solutions;
        int len = nums.size();
        for(int i=0; i<len; i++){
            if(i>0 && nums[i-1] == nums[i]) continue;
            for(int j=i+1; j<len; j++){
                if(j!=i+1 && nums[j-1] == nums[j]) continue;
                int target = -(nums[i] + nums[j]);
                if(target < nums[j])  continue;
                if(bisect_find(nums, j+1, len-1, target)){
                    vector<int> new_solution;
                    new_solution.push_back(nums[i]);
                    new_solution.push_back(nums[j]);
                    new_solution.push_back(target);
                    all_solutions.push_back(new_solution);
                }
            }
        }
        return all_solutions;

    }

    bool bisect_find(vector<int> &nums, int begin, int end, int ele){
        while(begin <= end){
            int mid = begin + (end-begin)/2;
            if(nums[mid] < ele)
                begin = mid + 1;
            else if(nums[mid] > ele){
                end = mid - 1;
            }else
                return true;
        }
        return false;
    }
};
