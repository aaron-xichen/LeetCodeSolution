#include "./solution.cpp"
int main(){
    ListNode *h1 = new ListNode(1);
    ListNode *l11 = new ListNode(2);
    ListNode *l12 = new ListNode(2);
    ListNode *h2 = new ListNode(100);
    ListNode *l21 = new ListNode(2);
    ListNode *l22 = new ListNode(2);

    h1->next = l11;
    l11->next =l12;
    h2->next = l21;
    l21->next = l22;

    vector<ListNode*> q;
    q.push_back(h1);
    q.push_back(h2);

    solution sl = solution();
    ListNode * head = sl.mergeKLists(q);
    while(head != NULL){
        cout<<head->val<<" ";
        head = head->next;
    }
}
