class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
        // now to make ans shortest, we don't make changes in common part of both strings,
        // so take LCS, fill the other chars in strings in the "correct order"
        // exp: s1 = "abac" s2 = "adb", 
        // LCS = "ab", other not matching chars in s2 = "d",
        // now place that "d" in anywhere between 'a' & 'b' in base string
        // ans: "adbac"
        // now how can we construct it?
        // use print Longest common subsequence problem to solve this
        // from dp table, if chars are matching then  put single occurance in ans sttring
        // if not matching means, we have to reduce either s1 OR s2, for this in dp table, we
        // max(left col, above col), so whatever string we are reduceing take that strings not-matching character and put in ans
        // in this way after loop over we might have either (i> 0 OR j>0) so put the remaining part in ans string
        // and that out final shortest answer

        // copied from Q.print longest common subsequence
        int n = text1.size();
        int m = text2.size();
        
        // with index shifting base case start from n coz, we can't handle negative indexes
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

        // convert states i, j into loops:   start i & j from 1, coz base case handled for 0
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                // copy recurrance

                if(text1[i-1] == text2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];

                // as we are returning from if case when its matches, or else only go further, so if its matches then it shouldn't enter no match state
                else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }

        // start constructing the answer
        string ans = "";
        
        int i = n, j = m;
        while(i > 0 && j > 0) {
            // if match then put char only once in ans
            if(text1[i-1] == text2[j-1]) {      // take text[i-1] coz used shifting on dp table, so i & j starts from n, m
                ans = text1[i-1] + ans;          // constructing ans from reverse so add new char to prev answer
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]) {
                // here we are going above row and reducing text1, so take the ommiting char from text1 to in ans
                ans = text1[i-1] + ans;
                i--;   /// above value is max, go above column
            }
            else {
                // and here we are reducing text2's char, so take it to ans
                ans = text2[j-1] + ans;
                j--;
            }
        }

        // one of the string might not be end in above loop
        while(i > 0) {                  // stop at 0 coz used "index shifting"
            ans = text1[i-1] + ans;
            i--;
        }

        while(j > 0) {
            ans = text2[j-1] + ans;
            j--;
        }
        return ans;
    }
};