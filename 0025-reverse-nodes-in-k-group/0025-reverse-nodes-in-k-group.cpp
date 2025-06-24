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

// use few pointer to store start of list to be reversed with its tail->next for connect the reversed tail to original next
// & also store prev of start to connect it with the reversed list head
// and connect start with original tail->next 
// if count != k then simply move current pointer further
// after reversing the k group reseat prevStart, curr & start pointers for next k group

class Solution {
public:

    ListNode* rev(ListNode* h) {
        ListNode *prev = NULL, *next;

        while(h) {
            next = h->next;
            h->next = prev;
            prev = h;

            h = next;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head->next || k == 1)       // No change needed
            return head;

        ListNode* newHead = new ListNode(-1, head);
        ListNode *curr = newHead->next;
        ListNode *prev = newHead;

        ListNode *st = head, *end = NULL, *end_next = NULL;
        int cnt = 0;

        while(curr) {
            cnt++;
            end_next = curr->next;

            if(cnt == k) {
                curr->next = NULL;          // break the link for reversing
                prev->next = rev(st);
                
                // prepare for new next part
                prev = st;              
                st->next = end_next;
                st = end_next;         
                cnt = 0;
            }

            curr = end_next;
        }

        return newHead->next;
    }
};