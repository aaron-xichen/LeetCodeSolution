#include "../solution.h"
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // trivial case
        if(NULL == head)
            return NULL;

        ListNode *fast = head;
        ListNode *slow = head;
        while(true){
            fast = fast->next;
            if(NULL == fast)
                return NULL;
            fast = fast->next;
            if(NULL == fast)
                return NULL;
            slow = slow->next;
            if(fast == slow)
                break;
        }

        slow = head;
        while(fast != slow){
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};
