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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // if any of the list is null means no need to merge them
        if(list1 == NULL)
            return list2;
        if(list2 == NULL)
            return list1;

        // first we have to handle setting head explicitly
        // we maintain head & tail for new modified merged list
        ListNode *head;
        ListNode *tail;

        // set head to one of the list head which has smaller  value
        // after setting head we have to move the list which head is selected for head in new List
        if(list1->val < list2->val) {
            head = list1;
            // tail = list1;         // initially tail will rest on head (which is first node of new list)
            list1 = list1->next;
        }
        else {
            head = list2;
            // tail = list2;         // initially tail will rest on head (which is first node of new list)
            list2 = list2->next;
        }

        tail = head;
        
        // now traverse both lists till end
        while(list1 != NULL && list2 != NULL)
        {
            // now we don't set we only modify our modified list's tail
            if(list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
                tail = tail->next;          // we have to move on new tail
            }
            else {
                tail->next = list2;
                list2 = list2->next;
                tail = tail->next;          
            }
        }

        // after loop any one of the list will be ended and remaining list we simply add as it is
        // after the tail coz there are no nodes in second list to compare with
        if(list1 == NULL)
            tail->next = list2;
        else 
            tail->next = list1;

        // at last return head of modified list
        return head;
    }
};