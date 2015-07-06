#include "../solution.h"
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return recursion(0, nums.size()-1, nums);
    }

    TreeNode* recursion(int begin, int end, vector<int>& nums){
        if(begin > end)
            return NULL;

        int mid_pos = (end - begin + 1) / 2 + begin;
        TreeNode* new_node = new TreeNode(nums[mid_pos]);
        new_node->left = recursion(begin, mid_pos-1, nums);
        new_node->right = recursion(mid_pos+1, end, nums);
        return new_node;
    }
};
