#include "../solution.h"
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> trees;
        if(n <= 0){
            trees.push_back(NULL);
            return trees;
        }
        TreeNode *root = new TreeNode(1);
        trees.push_back(root);
        for(int i=2; i<=n; i++){
            int size = trees.size();
            cout<<size<<endl;
            for(int j=0; j<size; j++){
                // traverse
                TreeNode *cur_ptr = trees[j];
                while(NULL != cur_ptr){
                    // insert as right child
                    TreeNode *right_child = cur_ptr->right;
                    TreeNode *new_node = new TreeNode(i);
                    cur_ptr->right = new_node;
                    new_node->left = right_child;
                    trees.push_back(copy(trees[j]));


                    // roll back and go deeper
                    cur_ptr->right = right_child;
                    cur_ptr = cur_ptr->right;
                }

                // add as root node
                TreeNode *new_node = new TreeNode(i);
                new_node->left = copy(trees[j]);
                trees[j] = new_node;
            }
        }

        return trees;
    }

    TreeNode *copy(TreeNode *root){
        if(NULL == root)
            return NULL;
        TreeNode *new_root = new TreeNode(root->val);
        new_root->left = copy(root->left);
        new_root->right = copy(root->right);
        return new_root;
    }
};
