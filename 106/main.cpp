#include "solution.cpp"
int main(){
    int in[] ={4,2,8,5,1,6,3,7};
    int post[] ={4,8,5,2,6,7,3,1};
    vector<int> inorder(in, in+8);
    vector<int> postorder(post, post+8);
    solution sl = solution();
    TreeNode *root = sl.buildTree(inorder, postorder);
    sl.print(root);

}
