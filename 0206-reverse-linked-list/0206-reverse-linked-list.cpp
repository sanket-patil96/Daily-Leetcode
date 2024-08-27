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
    ListNode* reverseList(ListNode* head) {
        // if head is null or head is only node then return head as it is
        if(head == NULL || head->next == NULL)
            return head;

        // we store previous node & next node pointer
        // use this node to store next of curr before changing it
        ListNode *prevNode = NULL;
        ListNode *next = NULL;      
        ListNode *curr = head;
        

        while(curr != NULL) {
            next = curr->next;
            curr->next = prevNode;  // swap nodes
            
            prevNode = curr;

            // we changed next pointer so its now stored in next node
            curr = next;
        }
        // at this point we are at NULL & prevNode at last node 
        // so return last node as head
        return prevNode;
    }
};