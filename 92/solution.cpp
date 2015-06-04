#include "../solution.h"
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *h = head;
        ListNode *pre = NULL;
        while(m > 1){
            pre = h;
            h = h->next;
            m--;
            n--;
        }
        if(pre == NULL)
            return reverse(h, n);
        else{
            pre->next = reverse(h, n);
            return head;
        }
    }

    // reverse list from head where length=len (included)
    ListNode *reverse(ListNode *head, int len){
        ListNode *current = head->next;
        ListNode *pre = head;
        len--;
        while(len > 0){
            ListNode *next = current->next;
            current->next = pre;
            pre = current;
            current = next;
            len--;
        }
        head->next = current;
        return pre;
    }
};
