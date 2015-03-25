struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){};
};

class Solution{
    public:
        ListNode *deleteDuplicate(ListNode *head){
            if(NULL==head || head->next == NULL){
                return NULL:
            }
            ListNode *h = head;
            while(NULL != h && NULL != h->next){
                if(h->val == h->next->val){
                    h->next = h->next->next;
                }else{
                    h = h->next;
                }
            }
            return head;
        }

};
