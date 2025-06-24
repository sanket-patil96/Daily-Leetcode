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
        if(!head->next || k == 1)       // No change
            return head;

        ListNode *prev = NULL;
        ListNode *curr = head;
        int cnt = 0;      

        ListNode *st = head, *end = NULL, *end_next = NULL;

        while(curr) {
            cnt++;
            end_next = curr->next;

            if(cnt == k) {
                curr->next = NULL;          // break the link for reversing

                ListNode *reversed = rev(st);
                
                if(!prev) 
                    head = reversed;
                else 
                    prev->next = reversed;
        
                
                // prepare for new next part
                prev = st;              
                st->next = end_next;
                st = end_next;         
                cnt = 0;
            }

            curr = end_next;
        }

        return head;
    }
};