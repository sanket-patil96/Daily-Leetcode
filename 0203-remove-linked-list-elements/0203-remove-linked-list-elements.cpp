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
    // approach1: iterative
    ListNode* removeElements(ListNode* head, int val) {
        // first check if head has to be change explicitly
        // move head till head->val != val
        while(head && head->val == val)
            head = head->next;

        // means after loop head reaches NULL means all nodes containing val == val
        if(!head)   
            return NULL;


        ListNode *curr = head;

        // loop till next Node is not NULL, coz we are checking next nodes data
        while(curr && curr->next)
        {
            // if next node having same val then break connection with it & don't move to next node
            // till next node's val != val
            if(curr->next->val == val)
                curr->next = curr->next->next;      
            else
                curr = curr->next;
        }

        return head;
    }
};