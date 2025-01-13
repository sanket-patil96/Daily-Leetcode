class Solution {
public:
    string removeOuterParentheses(string s) {
        // we store the opening parenthesis in stack 
        // if we found a closing parenthesis, then check if there anohter opening bracket present or not
        // if present means current bracket is inner-one so we can add it in answer
        // But after poping current opening bracket stack is empty then there is no outer bracket in string
        // so we don't include it in string

        stack<char> st;
        string ans = "";

        for(auto c: s) {
            if(c == '(') {
                st.push('(');

                // as if there are outer parenthesis other than current then we can add it in answer
                if(st.size() > 1)
                    ans += "(";
            }
            else {
                st.pop();

                // if there are outer parenthesis then only add the closing bracket, if this: "()" then don't add
                if(st.size() > 0)
                    ans += ")";
            }
        }

        return ans;
    }
};