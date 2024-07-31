class Solution {
public:
// from GFG Practice solution not complete for this solution!
// we just need to reverse the string between the space (' ') and at last reverse all string

    string reverseWords(string s) {
        // neive approach: using stack time: O(S) space: O(S)
        // use a stack and fill word and after that as stack is LIFO add words in answer it will be in reverse order
        // stack<string> st;
        // string word = "";
        // for(int i = 0; i < s.size(); i++) {
        //     if(s[i] == ' ') {
        //         if(word != "")
        //             st.push(word);
        //         word = "";
        //     }

        //     else 
        //         word += s[i];
        // }

        // // push the last word
        // if(word != "") 
        //     st.push(word);

        // string ans = "";
        // while(st.size() > 1) {
        //     ans += st.top() + " ";
        //     st.pop();
        // }

        // // do it out of loop for not adding extra space at last word
        // ans += st.top();
        // st.pop();

        // return ans;


        // using two pointers approach, add word in answer if there is ' ' in reverse order like ans = word + ans
        // time: O(s)  space: (1)
        string ans = "";
        string word = "";

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ') {
                if(word != "")
                    ans = " " + word + ans;           // to add it in reverse order
                word = "";
            }

            else 
                word += s[i];
        }

        // for adding last word
        if(word != "")  
            ans = word + ans;       

        // there is chance for extra space on front in loop, exp: "  hello world  "
        if(ans[0] == ' ')
            ans = ans.substr(1, ans.size()-1);

        return ans;
    }
};