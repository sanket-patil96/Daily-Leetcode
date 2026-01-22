class Solution {
public:
    int minInsertions(string s) {
        // variation of LPS
        // s = "mbadm" from this if we want insertion to make it palindrom, then first idea is
        // add reversed part of s to itself then the string becomes palindrome
        // insertions required will be of size s, but we have to minimize it, so
        // how can we minimize??
        // in "mbadm"  already present palindrome is "mam" so we just need to insert 2 chars, so we can make match for
        // remaining "bd" chars, possible ans: "mbdadbm"
        
        // so here we can get the answer by finding longest palindromic subsequence (LPS), from s
        // and reduce its size from original string size, that no.of insertion will be minimum

        return s.size() - longestPalindromeSubseq(s);
    }

    int longestPalindromeSubseq(string s) {
        string s1 = s;
        reverse(s1.begin(), s1.end());

        return longestCommonSubsequence(s, s1);
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<int> dp(m+1, 0);
        vector<int> temp(m+1, 0);
				
        for(int j = 0; j <= m; j++)  dp[j] = 0;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(text1[i-1] == text2[j-1])
                    temp[j] = 1 + dp[j-1];

                else temp[j] = max(temp[j-1], dp[j]);   // [j-1] was taken from the current row in 2D DP, so use temp for that
            }

            dp = temp;
        }

        return dp[m];
    }
};