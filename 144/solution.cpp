#include "../solution.h"
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> trace;
        TreeNode *cur = root;
        while(NULL != cur){
            if(NULL != cur->left){
                TreeNode *ptr = cur->left;
                while(NULL != ptr->right && ptr->right != cur)
                    ptr = ptr->right;
                if(NULL == ptr->right){
                    trace.push_back(cur->val);
                    ptr->right = cur;
                    cur = cur->left;
                }else{
                    ptr->right = NULL;
                    cur = cur->right;
                }
            }else{
                trace.push_back(cur->val);
                cur = cur->right;
            }
        }
        return trace;
    }
};
