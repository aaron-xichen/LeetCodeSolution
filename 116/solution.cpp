#include "../solution.h"
class solution{
    public:
        void connect(TreeLinkNode *root){
            if(NULL == root) return;
            queue<TreeLinkNode*> q;
            TreeLinkNode *delimiter = NULL;

            q.push(root);
            q.push(delimiter);

            TreeLinkNode * pre_node = root;
            TreeLinkNode * current_node;
            while(!q.empty()){
                current_node = q.front();
                q.pop();
                if(delimiter == current_node){
                    if(!q.empty()){
                        q.push(delimiter);
                        pre_node = q.front();
                        q.pop();
                        if(pre_node->left != NULL) q.push(pre_node->left);
                        if(pre_node->right != NULL) q.push(pre_node->right);
                    }
                    continue;
                }

                if(current_node != pre_node){
                    pre_node->next = current_node;
                    pre_node = current_node;
                }

                if(current_node->left != NULL) q.push(current_node->left);
                if(current_node->right != NULL) q.push(current_node->right);
            }
        }
};
