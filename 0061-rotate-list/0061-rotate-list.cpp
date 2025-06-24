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

        if(!head || !head->next || k == 0)
            return head;

        ListNode *curr = head, *tail = NULL;
        int n = 0;

        while(curr) {
            if(!curr->next)  tail = curr;
            curr = curr->next;
            n++;
        }

        // means k == n means no rotations required
        k = k % n;
        if(k == 0)  
            return head;

        ListNode *fast = head, *slow = head;

        // move fast for k times
        int c = 1;
        while(c < n-k) {
            fast = fast->next;
            c++;
        }

        // link both list parts (before rotation and after rotation parts)
        ListNode *newHead = fast->next;
        fast->next = NULL;
        tail->next = head;
        
        return newHead;
    }
};