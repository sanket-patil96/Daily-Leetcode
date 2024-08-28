/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node *flattenChilds(Node *head) {
        // if current node is only node without childs & next  then return it as tail of previous child list
        if(!head->next && !head->child) {
            return head;
        }

        if(head->child) {
            Node *next = head->next;
            head->next = head->child;

            head->child = NULL;

            Node *childTail = flattenChilds(head->next);
            childTail->next = next;

            // next might be null
            if(next)
                next->prev = childTail;

            return flattenChilds(childTail);        // next
        }

        else {
            head->next->prev = head;
            return flattenChilds(head->next);
        }
    }

    Node* flatten(Node* head) {
        // algo:
        // go next till we have childs for current node
        // store original next node and make next nodes prev = the tail of the child list
        // and childList's tail -> next = original next
        // at last connect all node's prev node to its previous to maintain doubly list

        Node *curr = head;

        while(curr) {
            if(curr->child) {
                Node *next = curr->next;
                curr->next = curr->child;

                curr->child = NULL;

                Node *childTail = flattenChilds(curr->next);
                childTail->next = next;

                if(next) {
                    next->prev = childTail;
                }

                curr = next;
            }
            else {
                curr = curr->next;
            }
        }

        // attach the prev for all nodes to make doubly list
        curr = head;
        Node *prev = NULL;
        while(curr) {
            curr->prev = prev;
            prev = curr;

            curr = curr->next;
        }

        return head;
    }
};