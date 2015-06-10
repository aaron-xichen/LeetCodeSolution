#include "../solution.h"
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        // trivial case
        if(nums.size() < 2)
            return 0;

        int max_value = INT_MIN;
        int min_value = INT_MAX;
        int len = nums.size();
        for(int i=0; i<len; i++){
            if(nums[i] > max_value)
                max_value = nums[i];
            if(nums[i] < min_value)
                min_value = nums[i];
        }

        // cout<<min_value<<endl;
        // cout<<max_value<<endl;

        int bucket_size = ceil(float(max_value-min_value) / (len-1));
        int bucket_num = ceil(float(max_value-min_value) / bucket_size);

        // cout<<bucket_size<<endl;
        // cout<<bucket_num<<endl;

        int lower_bound[bucket_num];
        int upper_bound[bucket_num];
        for(int i=0; i<bucket_num; i++){
            lower_bound[i] = INT_MAX;
            upper_bound[i] = INT_MIN;
        }

        for(int i=0; i<len; i++){
            int bucket_index = floor(float(nums[i] - min_value) / bucket_size);
            if(bucket_index == bucket_num)
                bucket_index--;
            lower_bound[bucket_index] = min(lower_bound[bucket_index], nums[i]);
            upper_bound[bucket_index] = max(upper_bound[bucket_index], nums[i]);
        }

        int max_gap = upper_bound[0] - lower_bound[0];
        int pre = upper_bound[0];
        for(int i=1; i<bucket_num; i++){
            if(lower_bound[i] != INT_MAX && upper_bound[i] != INT_MAX){
                max_gap = max(max_gap, lower_bound[i]-pre);
                pre = upper_bound[i];
            }
        }
        return max_gap;
    }

};
