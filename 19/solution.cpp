#include<iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL){};
};

class solution{
    public:
        ListNode *removeNthFromEnd(ListNode* head, int n){
            if(NULL == head) return NULL;
            ListNode *left = head;
            ListNode *right = head;
            for(int i=0; i<n; i++){
                right = right->next;
                if(NULL == right) return head->next;
            }
            while(NULL != right->next){
                left = left->next;
                right = right->next;
            }
            left->next = left->next->next;
            return head;
        }
};
