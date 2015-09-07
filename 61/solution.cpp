#include "../solution.h"
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        vector<ListNode*> v;
        while(NULL != head){
            v.push_back(head);
            head = head->next;
        }
        int len = v.size();
        if(len == 0)
            return NULL;
        k = k % len;
        if(k == 0 || len == 1)
            return v[0];
        ListNode *split = v[len - 1 - k];
        ListNode *next = v[len - k];
        ListNode *first = v[0];
        ListNode *tail = v[len - 1];

        tail->next = first;
        split->next = NULL;
        return next;
    }
};

