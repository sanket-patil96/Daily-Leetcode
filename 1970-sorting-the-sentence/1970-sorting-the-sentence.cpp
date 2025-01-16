class Solution {
public:
    string sortSentence(string s) {
        // we extract the numbers from the give words
        // index the words, and then use them in sorted order

        string ind[10];

        string word = "";
        for(auto c: s) {
            if(isdigit(c)) {
                ind[c-'0'] = word;
                word = "";
            }
            else if(c != ' ')
                word += c;
        }

        string ans = "";
        for(auto i: ind) {
            if(i.empty())   continue;
            
            if(ans.empty()) {
                ans += i;    
                continue;
            }
            ans += " " + i;
        }

        return ans;
    }
};