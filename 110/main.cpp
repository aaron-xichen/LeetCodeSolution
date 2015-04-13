#include "./solution.cpp"
int main(){
    TreeNode *root = new TreeNode(1);
    // TreeNode *l11 = new TreeNode(2);
    // TreeNode *l21 = new TreeNode(3);
    // root->right = l11;
    // l11->right = l21;

    solution sl = solution();
    bool isBalanced = sl.isBalanced(root);
    cout<<isBalanced<<endl;
}
