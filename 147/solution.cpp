#include "../solution.h"
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        // trivial case
        if (NULL == head)
            return NULL;
        if( NULL == head->next)
            return head;
        ListNode *new_list_header = head;
        ListNode *new_list_tail = head;

        ListNode *current_node = head->next;
        new_list_tail->next = NULL;
        while(NULL != current_node){
            // ListNode *print_ptr = new_list_header;
            // while(NULL != print_ptr){
                // cout<<print_ptr->val<<" ";
                // print_ptr = print_ptr->next;
            // }
            // cout<<endl;
            ListNode *iterator = new_list_header;
            if(current_node->val <= new_list_header->val){
                ListNode *tmp = current_node;
                current_node = current_node->next;
                tmp->next = new_list_header;
                new_list_header = tmp;
            }else if(current_node->val >= new_list_tail->val){
                new_list_tail->next = current_node;
                new_list_tail = current_node;
                current_node = current_node->next;
                new_list_tail->next = NULL;
            }else{
                while(iterator->next->val < current_node->val)
                    iterator = iterator->next;
                ListNode *tmp = current_node;
                current_node = current_node->next;
                tmp->next = iterator->next;
                iterator->next = tmp;
            }
        }
        return new_list_header;
    }
};

