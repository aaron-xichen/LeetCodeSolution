#include "../solution.h"
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(NULL == root) return root;
        TreeNode *left = invertTree(root->left);
        root->left = invertTree(root->right);
        root->right = left;
        return root;
    }
};
