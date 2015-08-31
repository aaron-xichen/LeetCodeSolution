#include "../solution.h"
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // trivial case
        if(NULL == head || NULL == head->next)
            return true;
        int length = 0;

        // compute the length
        ListNode *tmp = head;
        while(tmp != NULL){
            length++;
            tmp = tmp->next;
        }


        // reverset the list
        int mid = (length - 1) / 2;
        ListNode *pre = head;
        ListNode *cur = head;
        while(pre->next != NULL && mid > 0){
            ListNode *next = pre->next;
            pre->next = next->next;
            next->next = cur;
            cur = next;
            mid--;
        }

        // begin to check Palindrome
        ListNode *left, *right;
        if(length % 2 == 1)
            left = cur->next;
        else
            left = cur;
        right = pre->next;
        pre->next = NULL;
        while(left != NULL && right != NULL){
            if(left->val != right->val)
                return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }
};
