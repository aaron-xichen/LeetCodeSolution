#include "../solution.h"
class solution{
    public:
        int minDepth(TreeNode *root){
            int depth = 1;
            TreeNode* delimiter = NULL;
            if(NULL == root) return 0;
            queue<TreeNode*> q;
            q.push(root);
            q.push(delimiter);
            while(!q.empty()){
                TreeNode *current_node = q.front();
                q.pop();
                if(delimiter == current_node){
                    depth++;
                    if(!q.empty()){
                        q.push(delimiter);
                    }
                    continue;
                }
                if(current_node->left == NULL && current_node->right == NULL) return depth;
                if(current_node->left != NULL) q.push(current_node->left);
                if(current_node->right != NULL) q.push(current_node->right);
            }
            return depth;
        }
};
