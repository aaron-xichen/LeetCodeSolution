#include "../solution.h"
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *vir = new ListNode(-1);
        ListNode *tail = vir;
        bool is_carry = false;
        while(l1 != NULL || l2 != NULL){
            ListNode *next = new ListNode(0);
            if(is_carry){
                next->val ++;
                is_carry = false;
            }
            if(NULL != l1){
                next->val += l1->val;
                l1 = l1->next;
            }
            if(NULL != l2){
                next->val += l2->val;
                l2 = l2->next;
            }
            if(next->val > 9){
                next->val = next->val % 10;
                is_carry = true;
            }
            tail->next = next;
            tail = tail->next;
        }
        if(is_carry){
            tail->next = new ListNode(1);
        }
        return vir->next;
    }
};

