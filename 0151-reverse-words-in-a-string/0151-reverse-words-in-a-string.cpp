class Solution {
public:
    string reverseWords(string s) {
        // use a stack and fill word and after that as stack is LIFO add words in answer it will be in reverse order
        stack<string> st;
        string word = "";
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ') {
                if(word != "")
                    st.push(word);
                word = "";
            }

            else 
                word += s[i];
        }

        // push the last word
        if(word != "") 
            st.push(word);

        string ans = "";
        while(st.size() > 1) {
            ans += st.top() + " ";
            st.pop();
        }

        // do it out of loop for not adding extra space at last word
        ans += st.top();
        st.pop();

        return ans;
    }
};