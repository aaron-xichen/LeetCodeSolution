#include "./solution.cpp"
int main(){
    TreeNode *root = new TreeNode(1);
    TreeNode *left = new TreeNode(2);
    root->left = left;


    Solution sl = Solution();
    cout<<sl.lowestCommonAncestor(root, root, left)->val<<endl;
}

