class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // similar to postfix expression
        // push operands one by one from left to stack
        // when an operator comes, pop top 2 operands and put the current operator between them and push the result into stack
        // return final evaluated top value from stack

        stack<int> st;

        for(auto token: tokens) {
            if(token == "+" || token == "-" || token == "*" || token == "/") {
                int second = st.top();
                st.pop();
                int first = st.top();
                st.pop();

                int evaluate = evaluateExp(first, token, second);
                st.push(evaluate);
            }
            else 
                st.push(stoi(token));
        }

        return st.top();
    }

    int evaluateExp(int first, string token, int second) {
        if(token == "/") 
            return first / second;
        if(token == "*")
            return first * second;
        if(token == "-")
            return first - second;
        return first + second;
    }
};