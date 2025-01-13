class Solution {
public:
    string removeOuterParentheses(string s) {
        // we store the opening parenthesis in stack 
        // if we found a closing parenthesis, then check if there another opening bracket present or not
        // if present means current bracket is inner-one so we can add it in answer
        // But after poping current opening bracket stack is empty then there is no outer bracket in string
        // so we don't include it in string

        // now we can optimize it without using stack also in O(N) time & space
        // we use counter of opening brackets, usage same as the size of the stack.size() checking

        int opening = 0;
        string ans = "";

        for(auto c: s) {
            // as if there are outer parenthesis other than current then we can add it in answer
            if(c == '(' && opening++ > 0) 
                ans += c;

            // if there are outer parenthesis then only add the closing bracket, if this: "()" then don't add
            else if(c == ')' && opening-- > 1) 
                ans += c;
        }

        return ans;
    }
};