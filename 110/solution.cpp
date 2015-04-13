#include "../solution.h"
class solution{
    public:
        bool isBalanced(TreeNode *root){
            if(NULL == root)
                return true;
            if(height(root) == -1)
                return false;
            return true;
        }

        int height(TreeNode  *node){
            if(NULL == node){
                return 0;
            }
            int left = height(node->left);
            if(-1 == left)
                return -1;
            int right = height(node->right);
            if(-1 == right)
                return -1;
            int diff = (right>left)?right-left:left-right;
            if(diff > 1)
                return -1;
            else
                return max(right, left) + 1;
        }
};
