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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) 
            return head;

        ListNode *curr = head;

        while(curr->next != NULL)
        {
            // check this until next not become same
            // check if current node same as next node, if yes then remove it
            if(curr->val == curr->next->val)
            {
                ListNode *temp = curr->next->next;  // save location on next of same node
                delete curr->next;                  // delete same node
                curr->next = temp;                  // retrive locaiton of next of same node
            }
            
            // if next node is not same then move forward
            else
                curr = curr->next;
        }

        return head;
    }
};