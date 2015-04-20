#include "./solution.cpp"
int main(){
    TreeNode *root = new TreeNode(1);

    Solution sl = Solution();
    vector<vector<int> > result = sl.levelOrderBottom(root);
    for(int i=0; i<(int)result.size(); i++){
        for(int j=0; j<(int)result[0].size(); j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}
