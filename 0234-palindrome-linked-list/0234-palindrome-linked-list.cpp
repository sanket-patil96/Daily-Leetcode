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

    ListNode *reverseList(ListNode *mid)
    {
        ListNode *next = NULL;
        ListNode *prev = NULL;

        while(mid != NULL) {
            next = mid->next;
            mid->next = prev;
            prev = mid;

            mid = next;         // jump on next node
        }

        // our previous will remain on last node which is now our head
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        // find middle and reverse from middle
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != NULL && fast->next != NULL) 
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // now we have middle node on slow, reverse it
        ListNode *reversed = reverseList(slow);

        // now check first half & second reversed half
        while(reversed != NULL) {
            if(reversed->val != head->val)
                return false;

            reversed = reversed->next;
            head = head->next;
        }

        // loop successfully complete means all nodes are same!
        return true;
    }
};