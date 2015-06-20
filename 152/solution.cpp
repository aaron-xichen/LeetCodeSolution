#include "../solution.h"
class Solution {
public:
    int maxProduct(vector<int>& nums) {

        vector<int> container;
        int len = nums.size();

        // trivial case
        if(1 == len)
            return nums[0];

        int max_value = 0;
        int negative_nums = 0;
        int product = 1;
        for(int i=0; i<len; i++){
            int ele = nums[i];
            if(ele != 0){
                if(ele < 0)
                    negative_nums ++;
                product *= ele;

                int size = container.size();
                if(ele > 0 && size != 0 && container[size-1] > 0 )
                    container[size-1] = container[size-1] * ele;
                else
                    container.push_back(ele);
            }

            int size = container.size();
            if((ele == 0 || i == len-1) && size != 0){
                if(negative_nums % 2 == 0){
                    max_value = max(max_value, product);
                }else if(size == 1){
                    max_value = max(max_value, container[0]);
                }else{
                    // left-most negative
                    if(container[0] > 0){
                        max_value = max(max_value, container[0]);
                        max_value = max(max_value, product / container[0] / container[1]);
                    }else{
                        max_value = max(max_value, product / container[0]);
                    }

                    // right-most negative
                    if(container[size-1] > 0){
                        max_value = max(max_value, container[size-1]);
                        max_value = max(max_value, product / container[size-1] / container[size-2]);
                    }else{
                        max_value = max(max_value, product / container[size-1]);
                    }

                }
                container.clear();
                negative_nums = 0;
                product = 1;
            }
        }
        return max_value;
    }
};
