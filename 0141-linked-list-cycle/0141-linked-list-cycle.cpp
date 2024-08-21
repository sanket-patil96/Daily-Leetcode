/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // we try to use set of nodes -> next pointer storing in it if it appears again means 
        // loop detecter

        unordered_set<ListNode *> s;

        ListNode *curr = head;
        while(curr != NULL)
        {
            // if we find same pointer in set already present, then return true
            if(s.find(curr) != s.end()) 
                return true;

            s.insert(curr);
            curr = curr->next;
        }

        // the loop will only stop when curr becomes null means no loop
        return false;
    }
};