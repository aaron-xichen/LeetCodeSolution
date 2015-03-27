#include<iostream>
#include<stack>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};
class BSTIterator2{
    private:
        stack<TreeNode*> path;
    public:
        BSTIterator2(TreeNode *root){
            pushAll(root);
        }

        bool hasNext(){
            return !path.empty();
        }

        int next(){
            TreeNode *next = path.top();
            path.pop();
            pushAll(next->right);
            return next->val;
        }
        void pushAll(TreeNode * node){
            for(; NULL != node; path.push(node), node = node->left);
        }
};
