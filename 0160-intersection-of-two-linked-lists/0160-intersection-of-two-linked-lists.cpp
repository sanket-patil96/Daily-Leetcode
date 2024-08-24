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
        // efficient appraoch: time: O(m+n) (m is size of A & n is size of B) space: O(1)

        // 1. we count nodes of both lists (c1 & c2)
        // 2. we cut bigger list to make it same size of small list, by traversing bigger list
        //    abs(c1-c2) times
        // 3. now traverse both list's simulteneously until we found common node between them

        int c1 = 0;
        int c2 = 0;

        ListNode *a = headA;
        ListNode *b = headB;

        while(a != NULL)
        {
            c1++;
            a = a->next;
        }

        
        while(b != NULL)
        {
            c2++;
            b = b->next;
        }

        // now we find bigger list and cur down it by abs(c1-c2) nodes

        // reseting pointers to default for next operations
        a = headA;
        b = headB;

        // if A list is bigger 
        if(c1 > c2)
        {
            int d = c1 - c2;

            // move list A d nodes ahead
            for(int i = 0; i < d; i++)
                a = a->next;
        }

        // if B list is bigger
        else if(c2 > c1)
        {
            int d = c2 - c1;

            // move list A d nodes ahead
            for(int i = 0; i < d; i++)
                b = b->next;
        }

        // now we traverse both lists simulteneously 
        // as now both list size is same so we only add one condition in while loop
        while(a != NULL)
        {
            // first check coz new list can begin from list 1 itself
            // first list:  1->null
            // second list: ^ this is starting of second list; both are same here!
            if(a == b)
                return a;

            a = a->next;
            b = b->next;

        }

        // we come here means there is no intersection
        return NULL;
    }
};