#include "../solution.h"
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int total_value = 0;
        if(NULL == root)
            return total_value;
        recursion(root, 0, total_value);
        return total_value;
    }

    void recursion(TreeNode* node, int value, int &total_value){
        int current_value = 10 * value + node->val;
        if(NULL == node->left && NULL == node->right)
            total_value += current_value;
        if(NULL != node->left)
            recursion(node->left, current_value, total_value);
        if(NULL != node->right)
            recursion(node->right, current_value, total_value);
    }
};
