class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // convert to memoization
        // changing states are i, flag & no.of transaction (total 2 transaction only)
        // make dp of size [N][2][3], i is from 0-N, flag- 0/1, limit= 0/1/2

        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int>(3, -1)));

        // 1 transaction is done when we sell a previously bought stock
        // 2 is the limit of transactions, (stop when limit == 0)
        return solve(0, true, 2, prices, dp);
    }

    int solve(int i, bool flag, int limit, vector<int>& prices, vector<vector<vector<int>>> &dp) {
        // we cannot make any other transaction after that
        if(limit == 0)
            return 0;

        if(i == prices.size())
            return 0;

        if(dp[i][flag][limit] != -1)
            return dp[i][flag][limit];

        int profit = 0;

        // for a buy on current day there are 2 choices, buy the current stock and move on,
        // or dont' buy the current stock and move on, take max from both
        if(flag) {
            profit = max(  solve(i+1, false, limit, prices, dp) - prices[i],   // buy means, reduce it from the selling price to get profit
                        solve(i+1, true, limit, prices, dp)
                    );
        }

        // agian 2 way for selling on current day, either sell today or go to next days
        else  {
            profit =  max(  prices[i] + solve(i+1, true, limit-1, prices, dp),    // we make a transaction complete here by selling stock so limit-1
                            0 + solve(i+1, false, limit, prices, dp)
                        );
        }

        return dp[i][flag][limit] = profit;
    }
};