#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

class solution{
    public:
        TreeNode *buildTree(vector<int>&inorder, vector<int> &postorder){
            int len1 = (int)inorder.size();
            int len2 = (int)postorder.size();
            if(0 == len1 || 0 == len2) return NULL;
            return buildSubTree(postorder, inorder, 0, len1-1);
        }

        TreeNode *buildSubTree(vector<int> &postorder, vector<int> &inorder, int begin, int end){
            if(postorder.empty() || begin > end) return NULL;
            int root = postorder.back();
            postorder.pop_back();
            TreeNode * newNode = new TreeNode(root);
            for(int i=begin; i<=end; i++){
                if(inorder[i] == root){
                    newNode->right = buildSubTree(postorder, inorder, i+1, end);
                    newNode->left = buildSubTree(postorder, inorder, begin, i-1);
                    return newNode;
                }
            }
            return NULL;
        }
        void print(TreeNode *root){
            if(NULL == root) return;
            queue<TreeNode> q;
            q.push(*root);
            while(!q.empty()){
                TreeNode tmp = q.front();
                q.pop();
                cout<<tmp.val<<" ";
                if(tmp.left != NULL) q.push(*tmp.left);
                if(tmp.right != NULL) q.push(*tmp.right);
            }
            cout<<endl;
        }
};

