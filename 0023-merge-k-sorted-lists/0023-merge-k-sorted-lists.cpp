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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // use same min heap approach as used in sort lists
        if(lists.size() == 0)
            return NULL;

        priority_queue<ListNode*, vector<ListNode*>, function<bool(ListNode *, ListNode *)>> pq([](ListNode *a, ListNode *b){
            return a->val > b->val;
        });

        for(int i = 0; i < lists.size(); i++) {
            ListNode *curr = lists[i];
            while(curr) {
                pq.push(curr);
                curr = curr->next;
            }
        }
            
        ListNode *head = new ListNode(-1);
        ListNode *curr = head;

        while(!pq.empty()) {
            curr->next = pq.top();
            pq.pop();
            curr = curr->next;
        }

        // end the list
        curr->next = NULL;

        return head->next;
    }
};

