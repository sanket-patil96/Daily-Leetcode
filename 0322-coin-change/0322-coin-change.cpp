class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // using Tabulation
        // define base case
        // convert states into loops
        // copy recurrance

        int n = coins.size();

        vector<vector<int>> dp(n, vector<int> (amount+1, 1e8));
        
        // 1st base case: when amount becomes 0, return 0
        // amount can become 0 at any index
        for(int i = 0; i < n; i++)
            dp[i][0] = 0;

        // 2nd base case: at i = 0, return no.of coins required to reduce amount to 0, only if possible

        // this was in my mind, as from previous solved questions, but here is slight change
        // if(coins[0] != 0 && amount % coins[0] == 0)
        //     dp[0][amount] = amount / coins[0];

        // we have to mention no.of coins required of coins[0] for every amount i.e 0 <= amount
        // similar base case change as i used in 0/1 knapsack, as set val[0] for every dp[0][w] when w >= wt[0]
        if(coins[0] != 0)       // to avoid division/modulo by 0 error
            for(int a = 0; a <= amount; a++)
                if(a % coins[0] == 0)
                    dp[0][a] = a / coins[0];


        // states are index & amount, i starts from 1 as i == 0 covered in base case
        for(int i = 1; i < n; i++) {
            for(int a = 0; a <= amount; a++) {
                // copy recurrance from recursion solution:

                int take = 1e8;    
                if(coins[i] <= a) 
                    take = dp[i][a-coins[i]] + 1;

                int noTake = dp[i-1][a];

                dp[i][a] = min(take, noTake);
            }
        }

        int ans = dp[n-1][amount];
        return ans == 1e8 ? -1 : ans;
    }
};