#include "../solution.h"
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> travesal;
        recursion(root, travesal);
        return travesal;
    }
    void recursion(TreeNode *root, vector<int> &travesal){
        if(NULL == root)
            return;
        recursion(root->left, travesal);
        travesal.push_back(root->val);
        recursion(root->right, travesal);
    }
};
