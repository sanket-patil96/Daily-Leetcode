class Solution {
public:

    bool isMatch(char c, string &st) {
        if((c == ')' && st.back() == '(') || (c == ']' && st.back() == '[') || (c == '}' && st.back() == '{'))
            return true;
        return false;
    }

    bool isValid(string s) {
        // approach 2: using simple string without stack
        // store only open braces, and pop back when closed

        string st = "";

        for(auto c: s) {
            if(c == '(' || c == '[' || c == '{') 
                st += c;

            else if(!st.empty() && isMatch(c, st))
                st.pop_back();
            else 
                return false;
        }

        return st.empty();
    }
};