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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Algo:
        // 1. create a new list for storing the new addition of list
        // 2. move pointers with carry and add addition each time, update carry for next node
        // 3. at last if carrry remain means add another node for carry & return the next of dummy new List
        
        
        ListNode *newList = new ListNode(0);
        ListNode *curr = newList, *p1 = l1, *p2 = l2;       // current pointers of all list
        int carry = 0;


        // more clean code: 

        while(p1 || p2 || carry) {
            int sum = carry;

            if(p1) {
                sum += p1->val;
                p1 = p1->next;
            }
            
            if(p2) {
                sum += p2->val;
                p2 = p2->next;
            }
            
            int lastDigit = sum % 10;
            curr->next = new ListNode(lastDigit);
            carry = sum / 10;

            // move the pointer further
            curr = curr->next;
        }

        return newList->next;
    }       
};