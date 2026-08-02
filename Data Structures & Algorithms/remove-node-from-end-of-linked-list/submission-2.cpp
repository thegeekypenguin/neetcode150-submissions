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
    int getLengthOfLL(ListNode* head){
        int length = 0;
        while(head != nullptr){
            length++;
            head= head->next;
        }
        return length;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Two Pass Solution
        int L = getLengthOfLL(head);

        if(n == L){ // you have to delete the head
            ListNode* temp = head->next;
            delete(head);
            return temp;
        }
         
        int travel_from_front = L-n;
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while(travel_from_front--){
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        delete(temp);

        return head;
    }
};
