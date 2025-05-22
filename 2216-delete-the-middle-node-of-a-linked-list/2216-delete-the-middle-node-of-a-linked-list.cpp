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
        // using the fast & slow pointers

        if(!head || !head->next)
            return NULL;

        ListNode *slowPrev = NULL, *slow = head, *fast = head;

        while(fast && fast->next) {
            slowPrev = slow;        // update the previous pointer
            slow = slow->next;
            fast = fast->next->next;
        }

        slowPrev->next = slow->next;
        delete slow;

        return head;
    }
};