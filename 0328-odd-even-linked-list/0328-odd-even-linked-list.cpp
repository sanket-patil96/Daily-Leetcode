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
    ListNode* oddEvenList(ListNode* head) {
        // as we have to connect even & odd seperately, we can connect odds by 
        // connecting the next elements of the evens & can connect evens by next of the odds


        // base condition check
        // 3rd check for if there are no 2 odds, so no need to rearange (exp: 1->2->Null return as it is)
        if(!head || !head->next || !head->next->next)   
            return head;

        // for this we require few pointers, oddStart, oddEnd, EvnStart, EvnEnd
        ListNode *oddSt = head, *oddEnd = oddSt;
        ListNode *evnSt = head->next, *evnEnd = evnSt;

        // we only terminate by seing the end of the even list
        while(evnEnd && evnEnd->next) {
            // we are modifying the new pointers before changing the original one's

            // connect current odd with next odd (which come after its next even)
            oddEnd->next = evnEnd->next;
            oddEnd = oddEnd->next;
            
            // connect current evn with the next even which come after above modified oddEnd
            evnEnd->next = oddEnd->next;
            evnEnd = evnEnd->next;
        }

        // now at last connect the oddEnd with the starting of EvenEnd
        oddEnd->next = evnSt;
        return oddSt;
    }
};