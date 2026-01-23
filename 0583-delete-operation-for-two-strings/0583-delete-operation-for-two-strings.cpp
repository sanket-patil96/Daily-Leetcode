class Solution {
public:
    int minDistance(string word1, string word2) {
        // there is always a possible solution for this, we can remove whole s1 & s2, if not a single char don't match
        // so there is always a solution for this.
        // to minimize this, what needs to be done? we need to not delete the matching 
        // characters from both s1 & s2, which is keep common subsequence as it is
        // ex: "abcd" & "anc" here matching subsequence is "ac", so deletion required  in s1
        // are s1.size() - lcs, and deletions required for s2 are s2.size() - lcs
        // so we can use LCS solution for this
        
        int lcs = longestCommonSubsequence(word1, word2);
        
        int word1Deletions = word1.size() - lcs;
        int word2Deletions = word2.size() - lcs;
        
        return word1Deletions + word2Deletions;
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