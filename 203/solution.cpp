#include "../solution.h"
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *pre = new ListNode(0);
        ListNode *next;
        pre->next = head;

        head = pre;
        next = pre->next;
        while(NULL != next){
            cout<<next->val<<endl;
            if(next->val == val){
                next = next->next;
                pre->next = next;
            }else{
                pre = next;
                next = next->next;
            }
        }
        return head->next;
    }
};
