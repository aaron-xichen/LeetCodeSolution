#include "solution.cpp"
int main(){
    TreeNode *root = new TreeNode(3);
    TreeNode *l11 = new TreeNode(9);
    TreeNode *l12 = new TreeNode(20);
    TreeNode *l21 = new TreeNode(15);
    TreeNode *l22 = new TreeNode(7);
    TreeNode *l20 = new TreeNode(12);
    TreeNode *l31 = new TreeNode(100);
    TreeNode *l32 = new TreeNode(200);

    root->left = l11;
    root->right = l12;
    l11 ->left = l20;
    l12->left = l21;
    l12->right = l22;
    l21->left = l31;
    l21->right = l32;

    solution sl = solution();
    utils util = utils();
    vector<vector<int> > all = sl.zigzagLevelOrder(root);
    util.print(all);
}
