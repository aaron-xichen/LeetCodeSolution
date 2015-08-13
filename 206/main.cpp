#include "./solution.cpp"

int main(){
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(3);

    l1->next = l2;
    l2->next = l3;

    Solution sl = Solution();
    ListNode *tail = sl.reverseList(l1);
    while(tail != NULL){
        cout<<tail->val<<" ";
        tail = tail->next;
    }

}
