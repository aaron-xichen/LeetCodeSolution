#include "../solution.h"
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *vitural = new ListNode(-1);
        ListNode *cur = vitural;
        while(NULL != head){
            if(NULL != head->next && head->val == head->next->val){
                int ref = head->val;
                while(NULL != head && head->val == ref)
                    head = head->next;
            }else{
                cur->next = head;
                cur = cur->next;
                head = head->next;
                cur->next = NULL;
            }
        }
        return vitural->next;
    }
};
