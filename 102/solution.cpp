#include "../solution.h"
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int> > result;
        TreeNode *delimiter = NULL;
        queue<TreeNode*> q;
        // trivial case
        if(NULL == root){
            return result;
        }
        q.push(root);
        q.push(delimiter);
        vector<int> ele;
        result.push_back(ele);
        while(!q.empty()){
            TreeNode *current_node = q.front();
            q.pop();
            if(current_node == delimiter){
                if(!q.empty()){
                    vector<int> ele;
                    result.push_back(ele);
                    q.push(delimiter);
                }
                continue;
            }
            result.rbegin()->push_back(current_node->val);
            if(NULL != current_node->left)
                q.push(current_node->left);
            if(NULL != current_node->right)
                q.push(current_node->right);
        }
        return result;
    }
};
