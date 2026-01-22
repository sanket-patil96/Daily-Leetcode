class Solution {
public:
    int longestPalindromeSubseq(string s) {
        // palindrome means it reads same from forword & backword direction:
        // exp: aba, here reverse of it also aba 
        // so, how can it be variation of Longest Common Subsequence?
        // for LCS: s1 = 'aabbcaa'   s2 = 'aacbbaa' here if we want longest common subsequence then it is 
        // 'aabbaa'
        // & see that s2 is reverse of s1, so we can find LPS by using LCS

        string s1 = s;
        reverse(s1.begin(), s1.end());

        return longestCommonSubsequence(s, s1);
    }

    int longestCommonSubsequence(string text1, string text2) {
        // space optimization is possible as we are only using previous row

        int n = text1.size();
        int m = text2.size();

        vector<int> dp(m+1, 0);
        vector<int> temp(m+1, 0);
				
				// base case
        for(int j = 0; j <= m; j++)  dp[j] = 0;
        // no need to do same for i as only 1 row is there

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                // copy recurrance

                if(text1[i-1] == text2[j-1])
                    temp[j] = 1 + dp[j-1];

                else temp[j] = max(temp[j-1], dp[j]);   // [j-1] was taken from the current row in 2D DP, so use temp for that
            }

            dp = temp;
        }

        return dp[m];
    }
};