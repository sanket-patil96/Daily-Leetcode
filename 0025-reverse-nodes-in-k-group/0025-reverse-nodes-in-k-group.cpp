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
    ListNode *reverse(ListNode *head) {
        ListNode *prev = NULL;
        ListNode *next = NULL;
        while(head) {
            next = head->next;
            head->next = prev;
            prev = head;

            head = next;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        // use few pointer to store start of list to be reversed with its tail->next for connect the reversed tail to original next
        // & also store prev of start to connect it with the reversed list head
        // and connect start with original tail->next 
        // if count != k then simply move current pointer further
        // after reversing the k group reseat prevStart, curr & start pointers for next k group

        if(!head || !head->next || k == 1)
            return head;

        ListNode *newHead = new ListNode(-1, head);
        ListNode *curr = newHead->next;
        // curr = curr->next;
        ListNode *startPrev = newHead;
        ListNode *endNext = NULL;
        ListNode *start = head;                 // starting and ending of reversed list & prev of start to connect
        ListNode *end = NULL;  

        int cnt = 1;
        while(curr) {
            if(cnt == k) {
                endNext = curr->next;
                curr->next = NULL;
                startPrev->next = reverse(start);

                // connect the reversed tail to original tail->next node
                start->next = endNext;

                // change pointers & cnt for next k group
                startPrev = start;              // start is now tail of reversed part
                curr = endNext;
                start = curr;                   // nexxt starting point of list
                cnt = 1;
            }
            else {
                curr = curr->next;
                cnt++;
            }
        }

        ListNode *temp = newHead;
        newHead = newHead->next;
        delete temp;
        return newHead;
    }
};