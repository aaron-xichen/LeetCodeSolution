#include "../solution.h"
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ptr = 0;
        int size = nums.size();
        for(int i=0; i<size; i++){
            if(nums[i] == 0)
                continue;
            else if(i == ptr){
                ptr++;
                continue;
            }
            nums[ptr++] = nums[i];
        }
        for(int i=ptr; i<size; i++){
            nums[i] = 0;
        }
    }
};
