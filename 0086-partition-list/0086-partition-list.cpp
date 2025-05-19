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
    ListNode* partition(ListNode* head, int x) {
        // create 2 lists
        // first will link all the lesser nodes & 2nd will link all the greater OR equal nodes
        // at last connect tail of list1 with list2's head && make list2's tail next = NULL
        // return newHead as list1's head
        // 2 edge cases:
        //      1. all nodes less than X & all nodes {don't make list2's tail->next = NULL}
        //      2. all nodes greater than X {return list2}

        if(!head || !head->next)
            return head;

        // better written:
        ListNode lessDummy(0), moreDummy(0);  // Dummy heads
        ListNode* less = &lessDummy;
        ListNode* more = &moreDummy;

        while (head) {
            if (head->val < x) {
                less->next = head;
                less = less->next;
            } 
            else {
                more->next = head;
                more = more->next;
            }
            
            head = head->next;
        }

        more->next = nullptr;        // Terminate the 'more' list
        less->next = moreDummy.next; // Connect the two partitions

        return lessDummy.next;       // Return the real head
    }
};