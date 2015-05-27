#include "./solution.cpp"
int main(){
    ListNode *head = new ListNode(10);
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(3);
    head->next = l1;
    l1->next = l2;
    l2->next = l3;
    l3->next = l1;
    Solution sl = Solution();
    ListNode *cross = sl.detectCycle(head);
    cout<<cross->val<<endl;
}
