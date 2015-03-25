#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution{
    public:
        vector<int> postorderTraversal(TreeNode *root){
            stack<TreeNode*> s;
            vector<int> v ;
            if(NULL == root) return v;
            s.push(root);
            TreeNode *h;
            // while((h=s.top())!=nullptr){
            while(!s.empty()){
                h = s.top();
                v.push_back(h->val);
                s.pop();
                if(h->left) s.push(h->left);
                if(h->right) s.push(h->right);
                reverse(v.begin(), v.end());
            }
            return v;
        }
};

