#include "../solution.h"
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> solutions;
        string cur = "";
        recursion(root, solutions, cur);
        return solutions;
    }

    void recursion(TreeNode *root, vector<string> &solutions, string cur){
        if(NULL == root)
            return;
        cur += to_string(root->val) + "->";
        if(root->left == NULL && root->right == NULL){
            solutions.push_back(cur.substr(0, cur.length() - 2));
        }else {
            if(root->left != NULL)
                recursion(root->left, solutions, cur);
            if(root->right != NULL)
                recursion(root->right, solutions, cur);
        }
    }
};
