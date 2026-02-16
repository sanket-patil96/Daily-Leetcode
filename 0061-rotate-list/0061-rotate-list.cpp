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
    ListNode* rotateRight(ListNode* head, int k) {
        // first we get the min rotation if k is greater than size of list
        // i.e K%n, coz k > n means full rotation + some rotation, so we get that some rotations by formula directly
        // then move the fast pointer k nodes ahead, then move both fast & slow by 1 node till fast reaches end node
        // then cut list from slow and assign newHead as slow->next, and tail of list's next = head (fast->next = head)

        if(!head || !head->next || k == 0)
            return head;
        
        ListNode *slow = head, *fast = head;

        int n = 0;   // get the size of list
        while(slow) {
            slow = slow->next;
            n++;
        }

        k = k % n;   // get the size of k according to n (avoid overcounting)
        if(k == 0)
            return head;
        
        slow = head;
        
        while(k--) 
            fast = fast->next;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode *newHead = slow->next;
        slow->next = NULL;

        fast->next = head;
        return newHead;
    }
};