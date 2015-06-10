#include "../solution.h"
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *new_head = new ListNode(0);
        ListNode *new_tail = new_head;
        new_head->next = head;
        while(head != NULL && head->next != NULL){
            new_tail->next = head->next;
            head->next = head->next->next;
            new_tail->next->next = head;
            new_tail = head;
            head = new_tail->next;
        }
        return new_head->next;
    }
};
