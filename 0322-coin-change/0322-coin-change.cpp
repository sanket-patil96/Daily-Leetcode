class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // as we are only using previous and current row, we can space optimize it
        int n = coins.size();

        vector<int> dp(amount+1, 1e8);
        vector<int> temp(amount+1, 1e8);
        
        // 1st base case: when amount becomes 0, return 0
        // if amount 0, then return 0
        dp[0] = 0;

        // 2nd base case: at i = 0, return no.of coins required to reduce amount to 0, only if possible
        if(coins[0] != 0)       // to avoid division/modulo by 0 error
            for(int a = 0; a <= amount; a++)
                if(a % coins[0] == 0)
                    dp[a] = a / coins[0];


        // states are index & amount, i starts from 1 as i == 0 covered in base case
        for(int i = 1; i < n; i++) {
            for(int a = 0; a <= amount; a++) {
                // copy recurrance from recursion solution:

                int take = 1e8;    
                if(coins[i] <= a) 
                    take = temp[a-coins[i]] + 1;        // here we need to use the current row, coz u r allowed to take same coin again, so used temp (current array), dp is previous row here

                int noTake = dp[a];

                temp[a] = min(take, noTake);
            }

            dp = temp;
        }

        int ans = dp[amount];
        return ans == 1e8 ? -1 : ans;
    }
};