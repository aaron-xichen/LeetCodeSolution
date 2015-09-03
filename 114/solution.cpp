#include "../solution.h"
class Solution {
public:
    void flatten(TreeNode* root) {
        if(NULL != root){
            TreeNode *tmp = recursion(root, NULL);
            root->left = tmp->left;
            root->right = tmp->right;
        }
    }

    TreeNode* recursion(TreeNode* root, TreeNode* right_child){
        if(NULL == root->left && NULL == root->right)
            root->right = right_child;
        else if(NULL == root->left && NULL != root->right)
            root->right = recursion(root->right, right_child);
        else if(NULL != root->left && NULL == root->right){
            root->right = recursion(root->left, right_child);
            root->left = NULL;
        }else{
            root->right = recursion(root->left, recursion(root->right, right_child));
            root->left = NULL;
        }
        return root;
    }
};
