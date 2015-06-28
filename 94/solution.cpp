#include "../solution.h"
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> travesal;
        if(NULL == root)
            return travesal;

        stack<TreeNode*> trace;
        stack<TreeNode*> aux;
        if(root->right != NULL)
            trace.push(root->right);
        trace.push(root);
        if(root->left != NULL)
            trace.push(root->left);
        aux.push(root);

        while(!trace.empty()){
            TreeNode* trace_top = trace.top();
            trace.pop();
            // cout<<trace_top->val<<endl;
            if(aux.empty() || trace_top->val != aux.top()->val){
                if(trace_top->left != NULL && trace_top->right != NULL){
                    trace.push(trace_top->right);
                    trace.push(trace_top);
                    trace.push(trace_top->left);
                    aux.push(trace_top);
                }else if(trace_top->left == NULL && trace_top->right != NULL){
                    trace.push(trace_top->right);
                    trace.push(trace_top);
                    aux.push(trace_top);
                }else if(trace_top->left != NULL && trace_top->right == NULL){
                    trace.push(trace_top);
                    trace.push(trace_top->left);
                    aux.push(trace_top);
                }else{
                    travesal.push_back(trace_top->val);
                }
            }else{
                travesal.push_back(trace_top->val);
                aux.pop();
            }
        }
        return travesal;
    }
};
