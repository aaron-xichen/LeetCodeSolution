#include "../solution.h"
class solution{
    public:
        bool isSymmetric(TreeNode *root){
            if(NULL == root) return true;
            if(NULL == root->left && NULL != root->right) return false;
            if(NULL == root->right && NULL != root->left) return false;
            stack<TreeNode*> left_stack;
            stack<TreeNode*> right_stack;
            int len_left = pushAllLeft(root->left, left_stack);
            int len_right = pushAllRight(root->right, right_stack);
            if(len_left != len_right) return false;
            while(!left_stack.empty() && !right_stack.empty()){
                TreeNode *top_left = left_stack.top();
                TreeNode *top_right = right_stack.top();
                cout<<top_left->val<<" "<<top_right->val<<endl;
                if(top_left->val != top_right->val) return false;
                left_stack.pop();
                right_stack.pop();
                len_left = pushAllLeft(top_left->right, left_stack);
                len_right = pushAllRight(top_right->left, right_stack);
                if(len_left != len_right) return false;
            }

            if(left_stack.size() != right_stack.size()) return false;
            else return true;
        }

        int pushAllLeft(TreeNode * node, stack<TreeNode*> &left_stack){
            int len = 0;
            TreeNode * pointer = node;
            while(NULL != pointer){
                left_stack.push(pointer);
                pointer = pointer->left;
                len++;
            }
            return len;
        }

        int pushAllRight(TreeNode * node, stack<TreeNode*> &right_stack){
            int len = 0;
            TreeNode * pointer = node;
            while(NULL != pointer){
                right_stack.push(pointer);
                pointer = pointer->right;
                len++;
            }
            return len;
        }
};
