class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // need memoization to avoid TLE
        // changing states are index & amount, so 2D DP required
        // ind can go from 0 to n-1, and amount can go from 0 -> amount
        // so create dp of size: DP[n][amount+1] 
        // time: O(n*amount)  space: O(n*amount)

        int n = coins.size();

        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        int ans = solve(n-1, coins, amount, dp);

        // if amount can't be reduced to 0, then both take & noTake call return max(1e8, 1e8)
        return ans == 1e8 ? -1 : ans;
    }

    int solve(int i, vector<int> &coins, int amount, vector<vector<int>> &dp) {
        // stop when amount becomes 0
        if(amount == 0)
            return 0;

        if(i == 0) {
            // when there still amount remaining at last index, we have only option of using coins[0]
            // Only when if amount can be reduced to 0 by adding coins[0],
            // so coins required  of coins[0] to make amount to 0, are (amount / coins[0])
            if(amount % coins[0] == 0)
                return amount / coins[0];      

            // IF amount can't be reduced to 0, return max
            return 1e8; // to avoid error of signed integer overflow: 2147483647 + 1 on take call
        }

        if(dp[i][amount] != -1)
            return dp[i][amount];

        // keep taking current coin, (infinite supply of each coins)
        // but only when amount >= coins[i]
        int take = 1e8;    // SET TO MAX coz we are minimizing answer, so when take is wrong, then noTake should be selected
        if(coins[i] <= amount) 
            take = solve(i, coins, amount-coins[i], dp) + 1;        // +1 as we used this coin

        // don't use current coin
        int noTake = solve(i-1, coins, amount, dp);    

        // we need minimum coins that being used
        return dp[i][amount] = min(take, noTake);
    }
};