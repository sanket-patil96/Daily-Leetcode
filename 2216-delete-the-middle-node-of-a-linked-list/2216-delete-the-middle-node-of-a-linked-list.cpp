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
    ListNode* deleteMiddle(ListNode* head) {
        // we use slow & fast pointer to finding middle technique

        // corner case if head is null or head is only 1 node
        if(head == NULL || head->next == NULL)
            return NULL;


        ListNode *slow = head;
        ListNode *fast = head;
        // remain on slow pointer after slow updates, means at last it will on the previous 
        // node of middle node so we can remove middle node easily by disconnecting middle node
        ListNode *prev;         
        while(fast != NULL && fast->next != NULL) 
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // prev at previous of middle node slow at middle node; so disconnect prev with middle 
        // and connect with next of middle
        prev->next = slow->next;
        delete slow;        // delete middle node from memory

        return head;
    }
};