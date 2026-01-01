class Solution {
public:
    // int solve(int n, vector<int> &dp) {
    //     if(n == 0)
    //         return 1;
    //     if(n < 0)
    //         return 0;

    //     if(dp[n] != -1)
    //         return dp[n];

    //     return dp[n] = solve(n-1, dp) + solve(n-2, dp);
    // }

    int climbStairs(int n) {
        // using dynamic programming: O(N) solution

        // base case
        if(n == 0 || n == 1)
            return n;

        vector<int> dp(n+1, 0);
        dp[0] = 1, dp[1] = 1;       // there's only 1 way to reach 1, and for calculating 2nd stair we require previous 2 states

        for(int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
    }
};