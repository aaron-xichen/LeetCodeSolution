#include "../solution.h"
class solution{
    public:
        vector<vector<int> > pathSum(TreeNode *root, int sum){
            vector<vector<int> > all;
            vector<int> path;
            if(NULL == root) return all;
            recursion(all, path, root, 0, sum);
            return all;
        }

        void recursion(vector<vector<int> > &all, vector<int> &path, TreeNode *node, int sum_path, int sum){
            if(NULL == node->left && NULL == node->right){
                if(sum_path + node->val == sum){
                    path.push_back(node->val);
                    all.push_back(path);
                    path.pop_back();
                }
                return;
            }
            if(NULL != node->left){
                path.push_back(node->val);
                recursion(all, path, node->left, sum_path + node->val, sum);
                path.pop_back();
            }
            if(NULL != node->right){
                path.push_back(node->val);
                recursion(all, path, node->right, sum_path + node->val, sum);
                path.pop_back();
            }
        }
};
