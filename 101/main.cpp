#include "solution.cpp"
int main(){
    TreeNode *root = new TreeNode(1);
    TreeNode *l11 = new TreeNode(2);
    TreeNode *l12 = new TreeNode(3);
    TreeNode *l21 = new TreeNode(3);
    // TreeNode *l22 = new TreeNode(4);
    TreeNode *l23 = new TreeNode(2);
    // TreeNode *l24 = new TreeNode(2);

    root->left = l11;
    root->right = l12;
    l11->left = l21;
    // l11->right = l22;
    l12->left = l23;
    // l12->right = l24;

    solution sl = solution();
    cout<<sl.isSymmetric(root)<<endl;
}
