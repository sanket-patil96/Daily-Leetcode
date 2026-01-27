class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // there are some choices related with each step, so we can solve it recursively

        // convert memo to tabulation:
        // define base case
        // convert states into loops
        // copy the recurrance

        // need dp size [n+1][2]

        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2, 0));

        // base case: i == n; return 0 for every column
        dp[n][0] = 0;
        dp[n][1] = 0;

        for(int i = n-1; i >= 0; i--) {
            for(int j = 0; j <= 1; j++) {
                // copy the recurrance:

                int profit = 0;

                if(j == 1) {
                    profit = max(  dp[i+1][false] - prices[i],
                                   dp[i+1][true]
                            );
                }

                // agian 2 way for selling on current day, either sell today or go to next days
                else  {
                    profit = max(  prices[i] + dp[i+1][true],
                                    0 + dp[i+1][false]
                                );
                }

                dp[i][j] = profit;
            }
        }

        // answer will remain on first last cell of first row (as we started from n and goes till 0 for rows, & 0 to 1 for column)
        return dp[0][1];
    }
};