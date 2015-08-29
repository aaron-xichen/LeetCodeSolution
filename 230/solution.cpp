#include "../solution.h"
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        return recusion(root, k);
    }

    int recusion(TreeNode* root, int &k){
        if(NULL == root)
            return INT_MIN;

        if(NULL != root->left){
            int val = recusion(root->left, k);
            if(val != INT_MIN)
                return val;
        }

        k--;
        if(k == 0)
            return root->val;
        return recusion(root->right, k);
    }
};
