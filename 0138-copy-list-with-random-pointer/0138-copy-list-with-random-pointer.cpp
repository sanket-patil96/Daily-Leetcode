/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // neive approach: using hasing  time: O(n) space: O(n)
        // 1. create unordered_map
        // 2. do m[curr] = new Node(curr->data) for every node
        // 3. traverse given list again & do: 
        //      m[curr]->next = m[curr->next];
        //      m[curr]->random = m[curr->random];
        // 4. return m[head]

        // unordered_map<Node *, Node *> mp;

        // Node *curr = head;
        // while(curr != NULL)
        // {
        //     mp[curr] = new Node(curr->val);
        //     curr = curr->next;
        // }

        // curr = head;

        // while(curr != NULL)
        // {
        //     mp[curr]->next = mp[curr->next];
        //     mp[curr]->random = mp[curr->random];
        //     curr = curr->next;
        // }

        // return mp[head];


        // efficient approach: 
        // 1. create clone nodes and insert in the given list at alternate position
        // 2. connect clone nodes (with random pointers)
        // 3. seperate original & clone Nodes


        if(head == NULL)
            return head;

        // step 1: creating clone nodes in between
        Node *curr = head;
        while(curr != NULL)
        {
            Node *next = curr->next;            // store location of next 
            curr->next = new Node(curr->val);    // create clone node
            curr->next->next = next;            // make clone->next = original next

            curr = next;                        // go on original next node
        }

        // step 2: connect nodes with random pointers
        // 2 nodes ahead at time coz traversing on original nodes (there are clones between)
        for(curr = head; curr != NULL; curr = curr->next->next)
        {   
            // getting hold of colne's random
            // if curr->random is null then clones random is also null but, if not null
            // means, clones random is 1 node ahead of original random
            curr->next->random = (curr->random == NULL) ? NULL : (curr->random->next);
        }

        // step 3: seperate both clones and original nodes
        Node *head2 = head->next;  // clone head starts after original head 
        Node *clone = head2;

        for(Node *curr = head; curr != NULL; curr = curr->next) 
        {
            // if curr != null means there is its clone ahead, so dont need to check if next->next is we accessing null's -> next
            curr->next = curr->next->next;  // restore original next

            // but we have to check for clones->next to not null
            clone->next = clone->next ? clone->next->next : NULL;

            // move clone ahead
            clone = clone->next;
        }

        // return head of clone list
        return head2;       
    }
};