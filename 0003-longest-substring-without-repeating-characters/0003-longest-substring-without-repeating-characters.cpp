class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       // store indexes of chars on vector
       // get current starting index of non-repeted chars
       // get current not repeted chars length by decreasing starting point of current length
       // update previous array with current index of current array

        vector<int> prev(256, -1);      // store initially -1 so it don't give wrong length initially 
        int ans = 0;
        int startingInd = 0;

        for(int i = 0; i < s.size(); i++) {
            startingInd = max(startingInd, prev[s[i]] + 1);    //+1 coz length can't be 0
            int max_end = i - startingInd + 1;
            ans = max(ans, max_end);
            prev[s[i]] = i;
        }

       return ans;
    }
};