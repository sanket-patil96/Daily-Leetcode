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
    bool hasCycle(ListNode *head) {
        // method O(n) time
        // we use fast & slow pointer , initially both point to head, then slow moves 1 node &
        // fast moved 2 nodes eventually both meet on same node which create cycle if there is cycle

        ListNode *slow = head;
        ListNode *fast = head;

        // first condition is for even length, 2nd condition for odd length
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;        

            // check after moving pointers coz initially they are on same node
            if(slow == fast)
                return true;
        }

        // if fast reaches null means there is no cycle
        return false;
    }
};