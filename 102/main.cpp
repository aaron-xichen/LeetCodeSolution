#include "./solution.cpp"
int main(){
    Solution sl = Solution();
    TreeNode *root = new TreeNode(1);
    TreeNode *l11 = new TreeNode(2);
    root->left = l11;
    vector<vector<int> > result=sl.levelOrder(root);
    for(int i=0; i<(int)result.size(); i++){
        for(int j=0; j<(int)result[i].size(); j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}
