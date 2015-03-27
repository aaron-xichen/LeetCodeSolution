#include "solution2.cpp"
int main(){

    TreeNode * node31 = new TreeNode(13);
    TreeNode * node32 = new TreeNode(17);
    TreeNode * node21 = new TreeNode(1);
    TreeNode * node22 = new TreeNode(5);
    TreeNode * node23 = new TreeNode(14);
    TreeNode * node24 = new TreeNode(16);
    TreeNode * node11 = new TreeNode(4);
    TreeNode * node12 = new TreeNode(15);
    TreeNode * root = new TreeNode(9);

    root->left = node11;
    root->right = node12;

    node11->left = node21;
    node11->right = node22;
    node12->left = node23;
    node12->right = node24;

    node23->left = node31;
    node24->right = node32;


    BSTIterator2 sl = BSTIterator2(root);
    while(sl.hasNext()) cout<<sl.next()<<",";
}
