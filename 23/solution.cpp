#include "../solution.h"
class ComparisionClass{
    public:
        bool operator()(const ListNode*l1, const ListNode*l2){
            return l1->val > l2->val;
        }
};
class solution{
    public:
        ListNode *mergeKLists(vector<ListNode*> &lists){
            priority_queue<ListNode*, vector<ListNode*>, ComparisionClass> pq;
            ListNode *head = NULL;
            int len = lists.size();
            if(0 == len)
                return head;
            for(int i=0; i<len; i++){
                if(NULL != lists[i]){
                    pq.push(lists[i]);
                }
            }
            // construct the return value
            if(pq.empty())
                return head;
            head = pq.top();
            ListNode *ptr = head;
            pq.pop();

            // begin to loop
            while(!pq.empty()){
                if(ptr->next != NULL)
                    pq.push(ptr->next);
                ListNode *top  = pq.top();
                ptr->next = top;
                ptr = top;
                pq.pop();
            }
            return head;
        }
};
