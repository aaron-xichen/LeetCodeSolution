#include "../solution.h"
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(NULL == root)
            return false;
        if(NULL == root->left && NULL == root->right){
            return root->val == sum;
        }else{
            return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
        }
    }
};
