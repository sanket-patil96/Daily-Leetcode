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
    ListNode *detectCycle(ListNode *head) {

        // approach 2: we use floyd's cycle detection algorithm
        // for reference use detect loop in list problem

        // taking this ex: 1->2->3 where 3 again points to 1 in cycle
        
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != NULL && fast->next != NULL) 
        {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)
                break;
        }

        // to ensure the linked list has stopped becasue of null present
        if(fast == NULL || fast->next == NULL)
            return NULL;


        // else here our implementation for removing loop
        // we move our slow to head while fast remains on as it is

        slow = head;

        // we run a loop till slow != fast coz we have to stop at the meeting point
        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

    
        // now our fast & slow pointers at the start point of the cycle so return any one pointer
        return fast;
    }
};