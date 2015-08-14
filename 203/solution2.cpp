#include "../solution.h"
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head != NULL && head->val == val)
            head = head->next;
        if(NULL == head)
            return head;
        ListNode *next = head;
        while(NULL != next->next){
            if(next->next->val == val){
                next->next = next->next->next;
            }else{
                next = next->next;
            }
        }
        return head;
    }
};
