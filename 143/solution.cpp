#include "../solution.h"
class Solution {
public:
    void reorderList(ListNode* head) {
        int len = 0;
        ListNode *cur = head;
        while(NULL != cur){
            len++;
            cur = cur->next;
        }

        if(len <= 2)
            return;

        ListNode *pre = head;
        for(int i=0; i<len / 2; i++)
            pre = pre->next;

        // reverse
        ListNode *next;
        cur = pre;
        while(NULL != pre->next){
            next = pre->next;
            pre->next = next->next;
            next->next = cur;
            cur = next;
        }

        // concatate
        ListNode *next1, *next2;
        for(int i=0; i<len/2 - 1; i++){
            next1 = head->next;
            head->next = cur;
            next2 = cur->next;
            cur->next = next1;
            cur = next2;
            head = next1;
        }

        if( len % 2 == 1)
            head->next = cur;
    }
};
