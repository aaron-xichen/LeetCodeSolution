#include "../solution.h"
class solution{
    public:
        bool isBalanced(TreeNode *root){
            if(NULL == root)
                return true;
            int *h = height(root);
            if(-1 == h[0] || -1 == h[1])
                return false;
            return true;
        }

        int *height(TreeNode  *node){
            int *result=new int[2];
            result[0] = -1;
            result[1] = -1;
            if(NULL == node){
                result[0] = 0;
                result[1] = 0;
                return result;
            }
            int *left = height(node->left);
            if(-1 == left[0] || -1 == left[1])
                return result;
            int *right = height(node->right);
            if(-1 == right[0] || -1 == right[1])
                return result;
            int min = minimum(left[0], right[0]);
            int max = maximum(left[1], right[1]);
            if(max - min <=  1){
                result[0] = min+1;
                result[1] = max+1;
            }

            cout<<"val:"<<node->val<<" "<<result[0]<<" "<<result[1]<<endl;
            return result;
        }

        int minimum(int a, int b){
            return a<b?a:b;
        }
        int maximum(int a, int b){
            return a>b?a:b;
        }
};
