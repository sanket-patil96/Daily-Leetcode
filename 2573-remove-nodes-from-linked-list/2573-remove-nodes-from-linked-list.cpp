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
    ListNode* reverse(ListNode *head) {
        ListNode *prev = NULL;

        while(head) {
            ListNode *next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        // method 2: 
        // reverse the list & traverse
        // store max value till now if current node lesser than max then delete it
        if(!head || !head->next)
            return head;

        head = reverse(head);

        int max = head->val;
        ListNode *curr = head->next;
        ListNode *prev = head;

        while(curr) {
            // delete current node
            if(curr->val < max) {
                ListNode *temp = curr;
                curr = curr->next;
                delete temp;
            }

            else {
                max = curr->val;
                ListNode *next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
        }

        // we reversed the list so head should be end with NULL
        head->next = NULL;
        return prev;
    }
};