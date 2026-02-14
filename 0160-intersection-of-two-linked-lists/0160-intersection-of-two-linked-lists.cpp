/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int s1 = 0, s2 = 0;

        for(ListNode *curr = headA; curr; curr = curr->next)
            s1++;
        for(ListNode *curr = headB; curr; curr = curr->next)
            s2++;

        ListNode *curr1 = headA, *curr2 = headB;
        int moveAhead = abs(s1-s2);

        if(s1 > s2) 
            while(moveAhead--) 
                curr1 = curr1->next;
        else 
            while(moveAhead--) 
                curr2 = curr2->next;

        while(curr1) {
            if(curr1 == curr2)
                return curr1;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        return NULL;
    }
};