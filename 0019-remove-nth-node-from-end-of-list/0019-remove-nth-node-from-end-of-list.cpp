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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // approach 2: only 1 traversal required

        // we use 2 poninters approach here
        // handle corner case of head == NULL or head->next == NULL 
        // 1. we move fast 'n' positions ahead of head (n always within size)
        // 2. start slow pointer from head
        // 3. movef both pointers at same speed of 1 node at time. we stop when fast reaches at last node, so then 'slow' 
        //    will be at previous node of nth node (coz fast is ahead of n nodes)
        // 4. revome next of slow (which is nth node) from memory
        // 5. return head

        // if there is only 1 node n must be 1
        if(head == NULL || head->next == NULL) {
            delete head;
            return NULL;
        }

        ListNode *slow = head;
        ListNode *fast = head;      // we have to move 'fast' pointer 'n' nodes ahead
        
        for(int i = 0; i < n; i++)
            fast = fast->next;
        
        // here also we have to handle the case if we have to delete head node
        // here if our fast pointer reches null after putting in n nodes ahead means we have to 
        // delet head node
        if(fast == NULL) {
            return head->next;      // return second node as head
        }

        // we have to stop at previous node of nth from last
        while (fast->next != NULL)  
        {
            slow = slow->next;
            fast = fast->next;
        }
        
        // now we are at prev node of nth node from last (at 3 in example)
        ListNode *temp = slow->next;
        slow->next = slow->next->next;
        delete temp;        // delete nth node from last

        return head;
    }
};