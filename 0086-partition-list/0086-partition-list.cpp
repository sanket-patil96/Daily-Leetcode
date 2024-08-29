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

        ListNode *part1 = NULL;
        ListNode *prev1 = NULL;
        ListNode *part2 = NULL;
        ListNode *prev2 = NULL;
        ListNode *newHead = NULL;

        ListNode *curr = head;
        while(curr) {
            if(curr->val < x) {
                if(!newHead) {
                    part1 = curr;
                    newHead = part1;
                    prev1 = part1;
                }
                else {
                    prev1->next = curr;
                    prev1 = prev1->next;
                }
            }
            else {
                if(!part2) {
                    part2 = curr;
                    prev2 = part2;
                }
                else {
                    prev2->next = curr;
                    prev2 = prev2->next;
                }
            }

            curr = curr->next;
        }

        // make the last node next = NULL to end list If its not already NULL
        if(prev2)
            prev2->next = NULL;

        // new head is not set means all nodes has greater value than X so set list2's head as newhead
        if(!newHead) {
            return part2;
        }

        // connect partition1's tail with partition 2's head
        prev1->next = part2;

        return newHead;
    }
};