#include<iostream>
#include<stack>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};
class BSTIterator{
    private:
        stack<TreeNode*> path;
        stack<TreeNode*> aux;
    public:
        BSTIterator(TreeNode *root){
            if(NULL != root){
                path.push(root);
            }
        }

        bool hasNext(){
            return !path.empty();
        }

        int next(){
            TreeNode *top = path.top();
            while(true){
                // trace back node
                if(!aux.empty() && top == aux.top()){
                    path.pop();
                    aux.pop();
                    return top->val;
                // intermediate node
                } else {
                    path.pop();
                    if(NULL != top->right) path.push(top->right);
                    path.push(top);
                    aux.push(top);
                    if(NULL != top->left) path.push(top->left);
                    top = path.top();
                }
            }
        }
};
