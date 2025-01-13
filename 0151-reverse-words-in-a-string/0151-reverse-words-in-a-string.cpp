class Solution {
public:
    string reverseWords(string s) {
        // traverse from last of the string, add word in ans if we encounter ' '
        string word = "";
        string ans = "";

        for(int i = s.size()-1; i >= 0; i--) {
            char c = s[i];

            if(c == ' ' && word != "") {
                if(ans != "")
                    ans += " " + word;      // to avoid extra space get added at last
                else 
                    ans += word;
                word = "";
            }

            else if(c != ' ') {
                word = c + word;      // add in reverse order as we traversing from back
            }
        }

        if(word != "") {
            if(ans == "")
                ans += word;
            else 
                ans += " " + word;
        }
        
        return ans;
    }
};