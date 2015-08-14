#include "../solution.h"
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(NULL == head)
            return head;
        head->next = removeElements(head->next, val);
        return (val == head->val) ? head->next : head;
    }
};
