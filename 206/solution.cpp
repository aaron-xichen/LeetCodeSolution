#include "../solution.h"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(NULL != head && NULL != head->next){
            ListNode *tail = reverseList(head->next);
            ListNode *next = head->next;
            next->next = head;
            head->next = NULL;
            return tail;
        }
        return head;
    }
};
