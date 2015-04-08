#include "../solution.h"
class solution{
    public:
        vector<vector<int> > zigzagLevelOrder(TreeNode *root){
            vector<vector<int> > all;
            queue<TreeNode*> pipe;
            TreeNode* delimiter = NULL;
            pipe.push(root);
            pipe.push(delimiter);
            vector<int> one;
            bool isLeft = true;
            while(!pipe.empty()){
                TreeNode* current = pipe.front();
                pipe.pop();

                if(delimiter == current){
                    if(!isLeft)
                        reverse(one.begin(), one.end());
                    isLeft = !isLeft;
                    all.push_back(one);
                    one.clear();
                    if(!pipe.empty())
                        pipe.push(delimiter);
                    continue;
                }else{
                    one.push_back(current->val);
                }

                if(NULL != current->left){
                    pipe.push(current->left);
                    // one.push_back(current->left->val);
                }
                if(NULL != current->right){
                    pipe.push(current->right);
                    // one.push_back(current->right->val);
                }
            }
        return all;
        }
};

