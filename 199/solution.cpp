#include "../solution.h"
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> view;
        if(NULL != root)
            recursion(root, view, 0);
        return view;
    }

    void recursion(TreeNode* root, vector<int> &view, int depth){
        if((int)view.size() < depth + 1)
            view.resize(depth + 1);

        if(NULL != root->left)
            recursion(root->left, view, depth + 1);
        view[depth] = root->val;
        if(NULL != root->right)
            recursion(root->right, view, depth + 1);
    }
};
