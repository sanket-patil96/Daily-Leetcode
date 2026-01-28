class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // just the same thing as buy & sell II, where we can make infinite transactions
        // here just when we sell a stock, call for f(i+2) coz, next day is cooldown day
        // slight change in base case: if(i >= prices.size()) change is do ">="  as in this problem we calling for i+2, not i+1, so we may go beyong n with +2

        // copy as it is for memoization code of 122. Best Time to Buy and Sell Stock II:

        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));

        return solve(0, true, prices, dp);
    }

    int solve(int i, bool flag, vector<int>& prices, vector<vector<int>> &dp) {
        if(i >= prices.size()) {    // slight change is do ">="  as in this problem we calling for i+2, not i+1, so we may go beyong n with +2
            return 0;
        }

        if(dp[i][flag] != -1)
            return dp[i][flag];

        int profit = 0;

        // for a buy on current day there are 2 choices, buy the current stock and move on,
        // or dont' buy the current stock and move on, take max from both
        if(flag) {
            profit = max(  solve(i+1, false, prices, dp) - prices[i],   // buy means, reduce it from the selling price to get profit
                        solve(i+1, true, prices, dp)
                    );
        }

        // agian 2 way for selling on current day, either sell today or go to next days
        else  {
            profit = max(  prices[i] + solve(i+2, true, prices, dp),    // selling the stock, so call for i+2, as next day is cooldown period
                            0 + solve(i+1, false, prices, dp)
                        );
        }

        return dp[i][flag] = profit;
    }
};