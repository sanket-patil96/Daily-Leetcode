class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // apply memoization to avoid recomputing of overlapping subproblems
        // steps: 
        // find changing parameters: i & j
        // i can go till N & j till M, so create 2D DP for DP[N][M]
        // time: O(N*M)  space: O(N*M) + auxilary stack space for recursion

        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(n-1, m-1, text1, text2, dp);
    }

    int solve(int i, int j, string &text1, string &text2, vector<vector<int>> &dp) {
        if(i < 0 || j < 0)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        // if match add 1 ans & reduce index of both strings
        if(text1[i] == text2[j])
            return dp[i][j] = 1 + solve(i-1, j-1, text1, text2, dp);

        // if no match, we can't reduce both string index, coz this can miss out
        // for exp: "ec" & "ce", we are at index 1, if we reduce i&j at once we miss out common part "ee" OR "cc" 
        // so try reducing size from first string and then reduce for 2nd string & take max from both options
        return dp[i][j] = max(solve(i, j-1, text1, text2, dp), solve(i-1, j, text1, text2, dp));
    }
};