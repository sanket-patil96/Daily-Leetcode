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
        // algo:
        // if current has same value as next then run loop till its same
        // after loop check if prev->next is same to curr means no duplicates present at middle then move prev to prev->next node
        // else change the prev->next to curr->next
        if(!head || !head->next)
            return head;

        // Dummy node to handle edge cases smoothly
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr) {
            // Move to the last duplicate element
            while (curr->next && curr->val == curr->next->val) {
                curr = curr->next;
            }

            // If prev's next is curr, no duplicates were found
            if (prev->next == curr) {
                prev = prev->next;
            } else {
                // Skip all duplicates
                prev->next = curr->next;  // curr->next not equal to curr & curr is duplicate
            }
            
            curr = curr->next;
        }

        return dummy->next;
    }
};