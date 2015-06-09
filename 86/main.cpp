#include "./solution.cpp"
int main(){
    ListNode *head = new ListNode(1);
    ListNode *l1 = new ListNode(1);
    // ListNode *l2 = new ListNode(3);
    // ListNode *l3 = new ListNode(2);
    // ListNode *l4= new ListNode(5);
    // ListNode *l5= new ListNode(2);
    head->next = l1;
    // l1->next = l2;
    // l2->next = l3;
    // l3->next = l4;
    // l4->next = l5;

    Solution sl = Solution();
    sl.partition(head, 2);

    while(head != NULL){
        cout<<head->val<<" ";
        head = head->next;
    }
}
