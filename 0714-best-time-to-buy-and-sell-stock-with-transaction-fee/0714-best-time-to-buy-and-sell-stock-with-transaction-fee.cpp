class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // this version is also similar with the 2nd version of stocks
        // here also we can make multiple transactions
        // just change is when we sell stock the fee must be substracted from the profit
        // that's the slight chagne in this problem

        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));

        return solve(0, true, fee, prices, dp);  // true indicates we can buy the stock
    }

    int solve(int i, bool flag, int fee, vector<int> &prices, vector<vector<int>> &dp) {
        if(i == prices.size()) {
            return 0;
        }

        if(dp[i][flag] != -1)
            return dp[i][flag];

        int buy = 0, noBuy = 0;   // no buy means we can't buy but we can sell

        if(flag) {
            buy = max (
                    solve(i+1, false, fee, prices, dp) - prices[i],       // current prices should be reduced from its selling price
                    solve(i+1, true, fee, prices, dp)                    // don't buy on current day
            );
        }

        else {
            noBuy = max (
                    (prices[i] - fee) + solve(i+1, true, fee, prices, dp),       // sell previously bought stock, & next call for buying new stock
                    solve(i+1, false, fee, prices, dp)                            // sell on another day
            );
        }

        return dp[i][flag] = max(buy, noBuy);
    }
};