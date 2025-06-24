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
    ListNode* rotateRight(ListNode* head, int k) {
        // step1: take 2 pointers for kth node & for kth previous node as prev_k & kthNode
        // step2: we will stop on kth node from [last], then our prev_k pointing to previous of kth node
        // step3: we make prev_k->next = NULL as this wil be at end after connecting list
        // step4: and we start traversing from kthNode till last node of list
        // step5: we make last node's next = head node, this is how we join both parts
        // step5: return kthNode as new Head
        
        if(k == 0 || head == NULL || head->next == NULL)
            return head;        // return as it is


        // k can be greater than n means rotation can be of more than 1 lap
        // so we have to modulo it to get correct rotation count
        ListNode *curr = head;
        int length = 0;
        while(curr)
        {
            length++;
            curr = curr->next;
        }
        
        k = k % length;
        
        ListNode *prev_k = NULL;
        ListNode *kthNode = head;       // it will initially on head
        
        // to stoping on kth node from last we use this technique of fast & slow
        ListNode *fast = head;
        ListNode *slow = head;

        int cnt = 0;            // we move fast pointer k nodes ahed of head
        while(cnt < k && fast)
        {
            cnt++;
            fast = fast->next;
        }

        while(fast && fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }

        // now our slow will be on prev of k
        prev_k = slow;        // first we change prev_k
        kthNode = slow->next;
        
        // if k == N then our kthNode pointer will reach on end NULL, so
        // don't need to rotate whole list just return head as it is
        if(kthNode == NULL)
            return head;
        
        // step3:
        // our new head will be the kthNode
        // now our kthNode will be on kth node & prev_k will on previous of kth node
        ListNode *newHead = kthNode;
        prev_k->next = NULL;
    
        // step4: stop at last node
        while(kthNode->next) 
            kthNode = kthNode->next;
        
        // step5: 
        kthNode->next = head;       
        
        return newHead;
    }
};