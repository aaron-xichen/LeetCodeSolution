#include "../solution.h"
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // trivial case
        if(NULL == head)
            return false;

        ListNode* fast_ptr = head;
        ListNode* slow_ptr = head;
        // while(NULL != fast_ptr)
        while(NULL != fast_ptr->next && NULL != fast_ptr->next->next){
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
            if(fast_ptr == slow_ptr)
                return true;
        }
        return false;
    }
};
