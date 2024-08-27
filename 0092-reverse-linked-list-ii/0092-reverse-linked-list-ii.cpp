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
    ListNode *reverseSubList(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *next = NULL;

        while (head != NULL)
        {
            next = head->next;
            head->next = prev;
            prev = head;

            head = next;        // jump on next node
        }
        
        // at last our new head will be on prev
        return prev;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        // don't need to reverse list when left & right pointing to same node
        if(head == NULL || head->next == NULL || left == right)
            return head;

        // we keep left_prev, left, right, right_next nodes
        ListNode *left_prev = NULL;
        ListNode *leftNode = head;      // if left == 1 we wont set it in loop
        ListNode *rightNode = NULL;
        ListNode *right_next = NULL;

        int cnt = 1;
        ListNode *curr = head;

        while(cnt != right)
        {
            // if we are at prev of left node store both nodes
            if(cnt == left-1)
            {
                left_prev = curr;
                leftNode = curr->next;
            }

            curr = curr->next;
            cnt++;
        }

        // after loop over our curr will on the right position node
        // now store rightNode & right next
        rightNode = curr;
        right_next = curr->next;

        // we make rightNode next as null coz we have to stop reversing till rightNode we can do this making right nodes next null
        rightNode->next = NULL;

        // *** if left_prev is set, means it won't when left == 1 means we have to reverse from head, have to change head
        if(left_prev)
        {
            // now reverse list from leftNode till rightNode & assign its head to left_prev->next pointer
            left_prev->next = reverseSubList(leftNode);
        }
        else
            head = reverseSubList(leftNode);

        // now linked left-to-right reversed part to first half (head to left_prev) now we link 3rd remaining part(right to null)
        // our original leftNode node will be the last node of reversed part, so make its next = 3rd part(right_next)
        leftNode->next = right_next;

        return head;
    }
};