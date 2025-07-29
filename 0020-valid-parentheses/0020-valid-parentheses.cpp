class Solution {
public:

    bool isMatch(char c, stack<char> &st) {
        if((c == ')' && st.top() == '(') || (c == ']' && st.top() == '[') || (c == '}' && st.top() == '{'))
            return true;
        return false;
    }

    bool isValid(string s) {
        // store all open brackets on stack
        // if closing bracket occur, then check it match with the open bracket on top of stasck
        // if matches then pop the top 
        // else return false
        // at last if stack is empty and all string processed then return true

        stack<char> st;

        for(auto c: s) {
            if(c == '(' || c == '[' || c == '{') 
                st.push(c);

            else if(!st.empty() && isMatch(c, st))
                st.pop();
            else 
                return false;
        }

        return st.empty();
    }
};