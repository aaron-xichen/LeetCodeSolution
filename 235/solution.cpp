#include "../solution.h"
// generic situtaion, make no use of the binary property
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ancestor = NULL;
        bool p_is_find = false;
        bool q_is_find = false;
        recursion(root, p, q, p_is_find, q_is_find, &ancestor);
        return ancestor;
    }

    void recursion(TreeNode* cur, TreeNode* p, TreeNode* q, bool &p_is_find, bool &q_is_find, TreeNode** ancestor){
        bool cur_p_is_find = false;
        bool cur_q_is_find = false;
        if(cur->left != NULL)
            recursion(cur->left, p, q, cur_p_is_find, cur_q_is_find, ancestor);
        p_is_find |= cur_p_is_find;
        q_is_find |= cur_q_is_find;
        cur_p_is_find = false;
        cur_q_is_find = false;
        if(cur->right != NULL)
            recursion(cur->right, p, q, cur_p_is_find, cur_q_is_find, ancestor);
        p_is_find |= cur_p_is_find;
        q_is_find |= cur_q_is_find;

        if(cur == p) p_is_find |= true;
        if(cur == q) q_is_find |= true;

        if(p_is_find && q_is_find){
            if(NULL == *ancestor)
                *ancestor = cur;
            return;
        }
    }
};
