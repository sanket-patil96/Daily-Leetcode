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
    // using recursion
    ListNode* reverseList(ListNode* head, ListNode *next = NULL, ListNode *prev = NULL) {
        if(!head)
            return prev;

        next = head->next;
        head->next = prev;
        prev = head;
        head = next;

        return reverseList(head, next, prev);
    }
};