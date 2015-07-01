#include "../solution.h"
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* cur=root;
        TreeNode* pre;
        vector<int> solutions;
        while(cur != NULL){
            if(cur->left == NULL){
                solutions.push_back(cur->val);
                cur = cur->right;
            }else{
                pre = cur->left;
                while(NULL != pre->right && pre->right != cur)
                    pre = pre->right;
                if(pre->right == cur){
                    pre->right = NULL;
                    solutions.push_back(cur->val);
                    cur = cur->right;
                }else{
                    pre->right = cur;
                    cur = cur->left;
                }
            }
        }
        return solutions;
    }
};
