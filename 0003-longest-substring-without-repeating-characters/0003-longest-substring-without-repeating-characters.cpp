class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // we can simply track the each character's first occurance
        // if the same character appears again then length of that substring will be
        // current index - start (start = max(start, previous index of current char))
        // then update the current char index as current index & 'starting' point of current substring will be now
        // the next index of previous index of current char
        // dry run to get cleared!!

        unordered_map<char, int> m;
        int start = 0;
        int maxLen = 0;

        for(int i = 0; i < s.size(); i++) {
            // chage the start to next of previous occurance of current char
            if(m.count(s[i])) 
                start = max(start, m[s[i]]+1);

            maxLen = max(maxLen, i-start+1);         // +1 coz its lenght, (ex: 0-0 should be 1 as s = 'a' 1 char is there in string)
            m[s[i]] = i;
        }

        return maxLen;
    }
};