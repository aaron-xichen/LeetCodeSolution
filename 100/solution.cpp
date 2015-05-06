#include "../solution.h"
class Solution{
    public:
        bool isSameTree(TreeNode *p, TreeNode *q){
            if(NULL == p && NULL == q)
                return true;
            if(NULL == p && NULL != q)
                return false;
            else if(NULL != p && NULL == q)
                return false;
            else if(p->val != q->val)
                return false;
            else{
                return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
            }
        }
};
