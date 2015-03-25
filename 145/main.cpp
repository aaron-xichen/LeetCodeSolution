#include "solution.cpp"
int main(int argc, char *argv[])
{
    TreeNode  root = TreeNode(10);
    TreeNode  level11 = TreeNode(3);
    TreeNode  level12 = TreeNode(5);
    root.left = &level11;
    root.right = &level12;
    TreeNode  level21 = TreeNode(9);
    TreeNode level22 = TreeNode(111);
    level11.left = &level21;
    level11.right = &level22;
    TreeNode level23 = TreeNode(323);
    TreeNode level24 = TreeNode(23);
    level12.left = &level23;
    level12.right = &level24;

    Solution sol = Solution();
    vector<int> traversal = sol.postorderTraversal(&root);

    for(vector<int>::iterator it= traversal.begin();it!=traversal.end();it++){
        cout<<*it<<' ';
    }

    return 0;
}
