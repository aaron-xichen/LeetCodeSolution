#include "../solution.h"
class solution{
    public:
        ListNode *mergeTwoLists(ListNode *l1, ListNode *l2){
            if(NULL == l1) return l2;
            if(NULL == l2) return l1;
            ListNode *head = NULL;
            if(l1->val > l2->val){
                head = l2;
                l2 = l2->next;
            }else{
                head = l1;
                l1 = l1->next;
            }
            ListNode *tail = head;
            while(l1 != NULL || l2 != NULL){
                if(l1 == NULL){
                    tail->next = l2;
                    return head;
                }
                if(l2 == NULL){
                    tail->next = l1;
                    return head;
                }
                if(l1->val > l2->val){
                    tail->next = l2;
                    tail = l2;
                    l2 = l2->next;
                }else{
                    tail->next = l1;
                    tail = l1;
                    l1 = l1->next;
                }
            }
            return head;
        }
};
