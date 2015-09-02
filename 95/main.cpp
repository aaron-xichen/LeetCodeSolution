#include "./solution.cpp"
void print(TreeNode *node){
    if(NULL != node){
        cout<<node->val<<",";
        print(node->left);
        cout<<",";
        print(node->right);
    }else
        cout<<"#";
}
int main(){
    Solution sl = Solution();
    vector<TreeNode*> trees  = sl.generateTrees(3);
    for(int i=0; i<(int)trees.size(); i++){
        cout<<"{";
        print(trees[i]);
        cout<<"}";
    }
    string s = "";

}
