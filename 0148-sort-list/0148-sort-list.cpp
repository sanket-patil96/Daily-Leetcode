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
    ListNode* sortList(ListNode* head) {
        // use minHeap to store all the nodes & then connect them from top to bottom till heap becomes empty
        if (!head || !head->next)
            return head;

        // create min heap
        priority_queue<ListNode*, vector<ListNode*>, function<bool(ListNode*, ListNode*)>> pq([](ListNode* a, ListNode* b) { 
            return a->val > b->val; 
        });

        for (ListNode* curr = head; curr; curr = curr->next)
            pq.push(curr);

        // now connect them
        ListNode* curr = pq.top();
        pq.pop();
        ListNode *newHead = curr;

        while (!pq.empty()) {
            // cout << pq.top()->val << " ";
            curr->next = pq.top();
            curr = curr->next;
            pq.pop();
        }

        // end the list 
        curr->next = NULL;

        return newHead;
    }
};