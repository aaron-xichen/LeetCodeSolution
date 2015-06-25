#include "../solution.h"
class Solution{
public:
    vector<int> max_bitonic_seq(vector<int> nums){
        int len = nums.size();
        vector<int> left(len, 1);
        vector<int> right(len, 1);
        vector<int> route_map_left(len, 0);
        vector<int> route_map_right(len, 0);
        for(int i=0; i<len; i++){
            route_map_left[i] = i;
            route_map_right[i] = i;
        }

        for(int i=0; i<len; i++){
            for(int j=i+1; j<len; j++){
                if(nums[j] > nums[i]){
                    left[j] = left[i] + 1;
                    route_map_left[j] = i;
                }
            }
        }

        for(int i=len-1; i>=0; i--){
            for(int j=i-1; j>=0; j--){
                if(nums[j] > nums[i]){
                    right[j] = right[i] + 1;
                    route_map_right[j] = i;
                }
            }
        }

        // print
        // for(int i=0; i<len; i++){
            // cout<<left[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0; i<len; i++){
            // cout<<right[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0; i<len; i++){
            // cout<<route_map_left[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0; i<len; i++){
            // cout<<route_map_right[i]<<" ";
        // }
        // cout<<endl;

        int max_index = 0;
        int max_value = 0;
        for(int i=0; i<len; i++){
            if(left[i] + right[i] > max_value){
                max_index = i;
                max_value = left[i] + right[i];
            }
        }

        vector<int> result;
        int idx = max_index;
        while(route_map_left[idx] != idx){
            result.insert(result.begin(), nums[idx]);
            idx = route_map_left[idx];
        }
        result.insert(result.begin(), nums[idx]);
        idx = route_map_right[max_index];
        while(route_map_right[idx] != idx){
            result.push_back(nums[idx]);
            idx = route_map_right[idx];
        }
        result.push_back(nums[idx]);
        return result;
    }
};
