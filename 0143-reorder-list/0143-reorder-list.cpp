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
    ListNode *reverseList(ListNode *head)
    {
        if(head == NULL || head->next == NULL)
            return head;

        ListNode *prev = NULL;
        ListNode *next = NULL;

        ListNode *curr = head;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;

            curr = next; // jump on next node
        }

        // at last our new head will be on prev
        return prev;
    }
    
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return;
            
        // given list is:     l1 -> l2 -> l3 -> l4 -> l5
        // reorder list:      L1 -> l5 -> l2 -> l5 -> l3

        // Input: head:       1 -> 2 -> 3 -> (4 -> 5)
        // reversed lis:           5   ->    4           // ** observation: reversed part after mid
        // Output:            1 -> 5 -> 2 -> 4 -> 3

        // observation on given example:
        // we reverse list after middle node, make middle->next = NULL
        // and then connect each node of reversed list between 1st part(non-reversed)
        // we continue till any 1 part reaches null

        // 1st part = 1 -> 2 -> 3 -> null        2nd part after reversed = 5 -> 4 -> null
        //      1     2     3
        //       \   / \  /  \ 
        //         5    4     NULL 

        // here our *new list head is original list head
        // after that we *"alternatingly connecting"* next node with reversed list node & then original list node

        // step1: reach middle node and make its next null(make null after second step)
        // step2: reverse list after middle node
        // step3: connect reversed list nodes between original

        
        // step1: 
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // step2:
        // after that our slow will be on middle node, so make its next->null and seperate this part 
        // before that we reverse list after mid node till last node
        ListNode *reversedPart = reverseList(slow->next);
        slow->next = NULL;


        // step3: now we connect reversed list node after each original node, head will remian same
        ListNode *curr = head;
        while (reversedPart && curr)
        {
            ListNode *next = reversedPart->next;  // storing reversed lists next node before changing its next->link
            reversedPart->next = curr->next;     // store original next node after unlinking it with curr node
            
            curr->next = reversedPart;
            curr = curr->next->next;                // move on the original next node
            reversedPart = next;                    // it will jump on its next part
        }
    }
};