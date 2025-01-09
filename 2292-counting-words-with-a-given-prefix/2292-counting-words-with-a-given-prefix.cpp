class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        // check if prefix matches from starting of every word, if not break inner loop, & go for next word
        int cnt = 0;

        for(auto word: words)
            if(word.starts_with(pref))
                cnt++;
        

        return cnt;
    }
};