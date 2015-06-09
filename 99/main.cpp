#include "./solution.cpp"
void print(TreeNode*root);
int main(){
    TreeNode *root = new TreeNode(3);
    TreeNode *l1 = new TreeNode(2);
    TreeNode *l2 = new TreeNode(1);
    // TreeNode *l3 = new TreeNod(1);
    // TreeNode *l4 = new TreeNode(6);
    // TreeNode *l5 = new TreeNode(7);
    // TreeNode *l6 = new TreeNode(8);
    // TreeNode *l7 = new TreeNode(16);

    root->right = l1;
    l1->right = l2;
    // l1->left = l3;
    // l1->right = l4;
    // l2->left = l5;
    // l5->left = l6;
    // l5->right = l7;

    Solution sl = Solution();
    sl.print(root);
    sl.recoverTree(root);
    sl.print(root);
}


