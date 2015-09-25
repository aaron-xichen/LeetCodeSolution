#include "../solution.h"
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(NULL == head)
            return NULL;

        // construct vector to random access
        vector<ListNode*> eles;
        while(NULL != head){
            eles.push_back(head);
            head = head->next;
        }
        return recursion(eles, 0, eles.size() - 1);
    }

    TreeNode *recursion(vector<ListNode*> &eles, int begin, int end){
        if(begin > end)
            return NULL;
        else if(begin == end)
            return new TreeNode(eles[begin]->val);
        else{
            int mid = begin + (end - begin) / 2;
            TreeNode *par = new TreeNode(eles[mid]->val);
            par->left = recursion(eles, begin, mid - 1);
            par->right = recursion(eles, mid + 1, end);
            return par;
        }
    }
};
