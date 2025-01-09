class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        // check if prefix matches from starting of every word, if not break inner loop, & go for next word
        int cnt = 0;

        for(int i = 0; i < words.size(); i++) {
            int j = 0;
            for(j = 0; j < min(words[i].size(), pref.size()); j++) {
                if(words[i][j] != pref[j])
                    break;
            }
            if(j==pref.size())
                cnt++;
        }

        return cnt;
    }
};