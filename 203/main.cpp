#include "./solution3.cpp"
int main(){
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(3);
    ListNode *l4 = new ListNode(1);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;

    Solution sl = Solution();
    ListNode *head = sl.removeElements(l1, 1);
    while(head != NULL){
        cout<<head->val<<" ";
        head = head->next;
    }
}
