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

    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode *tail = &dummy;

        while(l1 && l2) {
            if(l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            }
            else {
                tail->next = l2;
                l2 = l2->next;
            }

            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;
        
        return dummy.next;
    }


    ListNode* sortList(ListNode* head) {
        // will use Merge sort
        // Split the list into two halves (using slow/fast pointers).
        // Sort each half recursively.
        // Merge the sorted halves.
        // Example:
        // Input: [4, 2, 1, 3]
        // Split: [4, 2] and [1, 3]
        // Sort: [2, 4] and [1, 3]
        // Merge: [1, 2, 3, 4]
        
        if(!head || !head->next)
            return head;

        ListNode *slow = head, *fast = head, *prev = NULL;

        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // break the list from midpoint
        prev->next = NULL;

        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(slow);

        return merge(l1, l2);
    }
};