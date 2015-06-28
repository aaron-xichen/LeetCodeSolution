#include "./solution2.cpp"
int main(){
    TreeNode* root = new TreeNode(1);
    TreeNode* l2 = new TreeNode(2);
    TreeNode* l3 = new TreeNode(3);
    TreeNode* l4 = new TreeNode(4);
    TreeNode* l5 = new TreeNode(5);
    TreeNode* l6 = new TreeNode(6);
    TreeNode* l7 = new TreeNode(7);
    TreeNode* l8 = new TreeNode(8);
    TreeNode* l9 = new TreeNode(9);

    root->left = l2;
    root->right = l3;
    l2->left = l4;
    l2->right = l5;
    l4->left= l8;
    l3->left = l6;
    l3->right = l7;
    l6->right = l9;

    Solution sl = Solution();
    vector<int> travesal = sl.inorderTraversal(root);
    for(int i=0; i<(int)travesal.size(); i++){
        cout<<travesal[i]<<" ";
    }
    cout<<endl;
}
