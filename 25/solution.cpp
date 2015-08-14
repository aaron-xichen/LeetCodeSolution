#include "../solution.h"
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // trivial case
        if(NULL == head){
            return head;
        }
        ListNode* vitural = new ListNode(0);
        vitural->next = head;
        ListNode *pre = head;
        for(int i=0; i<k-1; i++){
            if(pre->next == NULL){
                // rollback
                pre = vitural->next;
                while(pre->next != NULL){
                    ListNode *cur = pre->next;
                    pre->next = cur->next;
                    cur->next = vitural->next;
                    vitural->next = cur;
                }
                pre->next = NULL;
                return vitural->next;
            }
            ListNode *cur = pre->next;
            pre->next = cur->next;
            cur->next = vitural->next;
            vitural->next = cur;
        }

        pre->next = reverseKGroup(pre->next, k);
        return vitural->next;
    }
};
