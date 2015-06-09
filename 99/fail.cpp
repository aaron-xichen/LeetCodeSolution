#include "../solution.h"
class Solution {
public:

    void recoverTree(TreeNode* root) {
        // trivial case
        if(root == NULL)
            return;

        // while(true){
            TreeNode *abnormal_node = find_abnormal(root, INT_MIN, INT_MAX);
            // if(abnormal_node == NULL)
                // break;
            cout<<abnormal_node->val<<endl;
            TreeNode *insert_node = find_insert_node(root, abnormal_node);
            int tmp = abnormal_node->val;
            abnormal_node->val = insert_node->val;
            insert_node->val = tmp;
        // }
    }

    TreeNode* find_abnormal(TreeNode* root, int lo, int hi){
        if(NULL != root && (root->val < lo || root->val > hi))
            return root;

        TreeNode *abnormal_node = NULL;
        if(NULL != root->left)
            abnormal_node = find_abnormal(root->left, lo, min(hi, root->val));

        if(NULL == abnormal_node && NULL != root->right)
            abnormal_node = find_abnormal(root->right, max(lo, root->val), hi);
        return abnormal_node;
    }

    TreeNode* find_insert_node(TreeNode* root, TreeNode* compared_node){
        bool is_legal = false;
        if(root->left != NULL && root->right != NULL){
            is_legal = (root->left->val <= compared_node->val) &&
                (root->right->val >= compared_node->val);
        }else if(root->left != NULL && root->right == NULL){
            is_legal = root->left->val <= compared_node->val;
        }else if(root->left == NULL && root->right != NULL){
            is_legal = root->right->val >= compared_node->val;
        }else{
            return root;
        }
        if(is_legal)
            return root;

        // go deeper
        if(compared_node->val < root->val)
            return find_insert_node(root->left, compared_node);
        else
            return find_insert_node(root->right, compared_node);
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
