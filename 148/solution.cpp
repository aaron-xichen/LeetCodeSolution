#include "../solution.h"
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // trivial case
        if(NULL == head)
            return head;
        int counter = 0;
        ListNode* cur = head;
        while(cur != NULL){
            counter ++;
            cur = cur->next;
        }
        return mergeSort(head, counter);
    }

    ListNode* mergeSort(ListNode* head, int length){
        if(length == 1){
            head->next = NULL;
            return head;
        }else if(length == 2){
            if(head->val > head->next->val){
                ListNode *tmp = head->next;
                head->next->next = head;
                head->next = NULL;
                return tmp;
            }
        }

        int half = length / 2;
        ListNode* another = head;
        for(int i=0; i<half; i++){
            another = another->next;
        }
        ListNode *l1 = mergeSort(head, half);
        ListNode *l2 = mergeSort(another, length-half);

        ListNode *new_head = new ListNode(0);
        ListNode *pre = new_head;
        while(NULL != l1 || NULL != l2){
            if(NULL == l1){
                pre->next = l2;
                l2 = l2->next;
            }else if(NULL == l2){
                pre->next = l1;
                l1 = l1->next;
            }else if(l1->val <= l2->val){
                pre->next = l1;
                l1 = l1->next;
            }else{
                pre->next = l2;
                l2 = l2->next;
            }
            pre = pre->next;
        }
        pre->next = NULL;
        return new_head->next;
    }
};
