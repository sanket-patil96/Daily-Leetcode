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
        if(!head || !head->next)
            return NULL;
        
        ListNode *behind = head, *ahead = head;
        int i = 0; 

        while(ahead && i++ < n) 
            ahead = ahead->next;

        // if ahead reaches NULL mean we have to delete the head node (means n is then length of list)
        if(!ahead) {
            return head->next;
        }

        while(ahead->next) {
            behind = behind->next;
            ahead = ahead->next;
        }

        behind->next = behind->next->next;
        return head;
    }
};