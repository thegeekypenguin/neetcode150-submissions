/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /* Using TWO-POINTER approach
        1. Create a dummy node pointing to the head (helps handle deletion of the first node).
        2. Set two pointers: left at dummy, right at head
        3. Move right forward n steps.
        4. Move both pointers until right reaches the end.
        5. Now left.next is the node to delete → skip it by doing left.next = left.next.next.
        6. Return dummy.next as the updated head.
        */

        ListNode* dummy = new ListNode(0, head);
        ListNode* left = dummy;
        ListNode* right = head;

        while(n>0){
            right = right->next;
            n--;
        }

        while(right != nullptr){
            left = left->next;
            right = right->next;
        }

        left->next = left->next->next;
        return dummy->next;
    }
};







