#include "../solution.h"
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return recursion(root, LONG_MAX, LONG_MIN);
    }

    bool recursion(TreeNode* root, long upper_bound, long lower_bound){
        if(root == NULL)
            return true;
        if(root->val >= upper_bound || root->val <= lower_bound)
            return false;
        return recursion(root->left, min(upper_bound, (long)root->val), lower_bound) &&
            recursion(root->right, upper_bound, max(lower_bound, (long)root->val));
    }
};
