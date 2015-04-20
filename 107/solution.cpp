#include "../solution.h"
class Solution{
    public:
        vector<vector<int> > levelOrderBottom(TreeNode *root){
            vector<vector<int> > result;
            queue<TreeNode*> q;
            TreeNode *delimiter = NULL;
            if(NULL == root) return result;
            q.push(root);
            q.push(delimiter);
            vector<int> tmp;
            while(!q.empty()){
                cout<<".."<<endl;
                TreeNode *front = q.front();
                q.pop();
                if(delimiter == front){
                    if(!q.empty())
                        q.push(delimiter);
                    result.insert(result.begin(), tmp);
                    tmp.clear();
                }else{
                    tmp.push_back(front->val);
                    if(front->left != NULL) q.push(front->left);
                    if(front->right != NULL) q.push(front->right);
                }
            }
            return result;
        }
};
