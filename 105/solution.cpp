#include "../solution.h"
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorder_map;
        int pre_idx = 0;
        for(int i=0; i<(int)inorder.size(); i++){
            inorder_map.insert(pair<int, int>(inorder[i], i));
        }
        return recursion(preorder, pre_idx, inorder, 0, inorder.size()-1, inorder_map);
    }

    TreeNode* recursion(vector<int>& preorder, int &pre_idx,
            vector<int> &inorder, int inorder_idx_begin, int inorder_idx_end, unordered_map<int, int> &inorder_map){
        if(pre_idx > (int)preorder.size() - 1)
            return NULL;
        int pivot = preorder[pre_idx];
        TreeNode *current_node = new TreeNode(pivot);
        if(inorder_idx_begin < inorder_idx_end){
            int split_idx = inorder_map.find(pivot)->second;
            current_node->left = split_idx > inorder_idx_begin ? recursion(preorder, ++pre_idx, inorder, inorder_idx_begin, split_idx-1, inorder_map) : NULL;
            current_node->right = split_idx < inorder_idx_end ? recursion(preorder, ++pre_idx, inorder, split_idx+1, inorder_idx_end, inorder_map) : NULL;
        }
        return current_node;
    }
};
