#include "./solution.cpp"
int main(){
    TreeNode *root = new TreeNode(1);
    TreeNode *l11 = new TreeNode(-1);
    TreeNode *l12 = new TreeNode(-2);
    TreeNode *l21 = new TreeNode(-3);
    TreeNode *l22 = new TreeNode(1);
    TreeNode *l23 = new TreeNode(3);
    TreeNode *l24 = new TreeNode(-2);
    TreeNode *l31 = new TreeNode(-1);

    // root->left = l11;
    // root->right = l12;
    // l11->left = l21;
    // l11->right = l22;
    // l12->left = l23;
    // l12->right = l24;
    // l21->right = l31;

    solution sl = solution();
    vector<vector<int> > all = sl.pathSum(root, 1);
    for(int i=0; i< (int)all.size(); i++){
        for(int j=0; j<(int)all[0].size(); j++){
            cout<<all[i][j]<<" ";
        }
        cout<<endl;
    }
}
