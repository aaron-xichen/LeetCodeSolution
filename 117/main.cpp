#include "./solution.cpp"
int main(){
    TreeLinkNode *root = new TreeLinkNode(0);
    TreeLinkNode *l11 = new TreeLinkNode(1);
    TreeLinkNode *l12 = new TreeLinkNode(2);
    TreeLinkNode *l21 = new TreeLinkNode(3);
    TreeLinkNode *l22 = new TreeLinkNode(4);
    TreeLinkNode *l23 = new TreeLinkNode(5);
    TreeLinkNode *l24 = new TreeLinkNode(6);

    root->left = l11;
    root->right = l12;
    l11->left = l21;
    l11->right = l22;
    l12->left = l23;
    l12->right = l24;

    solution sl = solution();
    sl.connect(root);
}



