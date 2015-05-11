#include "../solution.h"
class Solution{
    public:
        int maxPathSum(TreeNode *root){
            //trivial case
            if(NULL == root)
                return 0;
            int max_go_through_sum = root->val;
            int max_seen_value = root->val;
            if(NULL != root->left)
                max_go_through_sum += max(0, maxSumToBottom(root->left, max_seen_value));
            if(NULL != root->right)
                max_go_through_sum += max(0, maxSumToBottom(root->right, max_seen_value));
            return max(max_go_through_sum, max_seen_value);
        }

        int maxSumToBottom(TreeNode *current_node, int &max_seen_value){
            int max_sum_to_bottom = current_node->val;
            if(NULL == current_node->left && NULL == current_node->right){
                max_seen_value = max(max_seen_value, current_node->val);
            }else if(NULL != current_node->left && NULL == current_node->right){
                max_sum_to_bottom += max(0, maxSumToBottom(current_node->left, max_seen_value));
                max_seen_value = max(max_seen_value, max_sum_to_bottom);
            }else if(NULL == current_node->left && NULL != current_node->right){
                max_sum_to_bottom += max(0, maxSumToBottom(current_node->right, max_seen_value));
                max_seen_value = max(max_seen_value, max_sum_to_bottom);
            }else{
                int left = max(0, maxSumToBottom(current_node->left, max_seen_value));
                int right = max(0, maxSumToBottom(current_node->right, max_seen_value));
                max_sum_to_bottom += max(left, right);
                int go_through_sum = left + current_node->val + right;
                max_seen_value = max(max_seen_value, go_through_sum);
            }
            return max_sum_to_bottom;
        }
};
