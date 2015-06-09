#include "../solution.h"
class Solution {
public:
    TreeNode *pre, *s1, *s2;
    void recoverTree(TreeNode* root) {
        recursion(root);
        swap(s1->val, s2->val);
    }

    void recursion(TreeNode *root){
        if(NULL == root)
            return;

        recursion(root->left);
        if(pre && pre->val > root->val){
            if(s1 && s2){
                s2 = root;
                return;
            }else{
                s1 = pre;
                s2 = root;
            }
        }
        pre = root;
        recursion(root->right);
    }

    void print(TreeNode*root){
        if(root->left == NULL && root->right == NULL){
            cout<<root->val<<endl;
            return;
        }
        if(root->left != NULL)
            print(root->left);
        cout<<root->val<<endl;
        if(root->right != NULL)
            print(root->right);
    }
};
