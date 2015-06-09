#include "../solution.h"
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *first_head = new ListNode(-1);
        ListNode *first_tail = first_head;
        ListNode *second_head= new ListNode(-1);
        ListNode *second_tail = second_head;

        while(head != NULL){
            if(head->val < x){
                first_tail->next = head;
                first_tail = first_tail->next;
            }else{
                second_tail->next = head;
                second_tail = second_tail->next;
            }
            head = head->next;
        }
        first_tail->next = second_head->next;
        second_tail->next = NULL;
        return first_head->next;
   }
};
