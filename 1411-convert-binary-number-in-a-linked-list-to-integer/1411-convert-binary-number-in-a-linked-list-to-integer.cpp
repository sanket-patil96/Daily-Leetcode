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
    int getDecimalValue(ListNode* head) {
        // reference: https://www.geeksforgeeks.org/program-binary-decimal-conversion/
        // we first get the whole binary number in string format for not overflow 
        // then we perform operation on each index in that string binary number to get decimal
        
        // string binary = "";

        // ListNode *temp = head;
        // while(temp) {
        //     binary += to_string(temp->val);
        //     temp = temp->next;
        // }

        // int n = binary.size();
        // int decimal = 0;
        // for(int i = 0; i < n; i++)
        //     decimal += (binary[i]-'0') * pow(2, n-i-1);     // n-i-1 to get 0-indexed base value
        
        // return decimal;


        int ans = 0;
        ListNode* temp = head;
        while(temp){
            ans = ans*2 + temp->val;
            temp = temp->next;
        }
        return ans;
    }
};