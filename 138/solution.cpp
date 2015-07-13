#include "../solution.h"
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // trivial case
        if(NULL == head) return head;

        // frist pass, multiply
        RandomListNode *begin = head;
        while(NULL != begin){
            RandomListNode *new_node = new RandomListNode(begin->label);
            new_node->next = begin->next;
            begin->next = new_node;
            begin = new_node->next;
        }

        // second pass, copy random pointer field
        begin = head;
        while(NULL != begin){
            if(NULL != begin->random)
                begin->next->random = begin->random->next;
            begin = begin->next->next;
        }

        // third pass, detach
        begin = head;
        RandomListNode *copy = head->next;
        while(NULL != begin->next){
            RandomListNode *next = begin->next;
            begin->next = begin->next->next;
            begin = next;
        }
        return copy;

    }
};
