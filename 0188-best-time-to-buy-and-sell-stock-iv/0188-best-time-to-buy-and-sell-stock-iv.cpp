class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // now convert to tabulation
        // define base case
        // convert states into loops
        // copy recurrance
        // return the same state as used in initial call of recursion

    
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int>(k+1, 0)));       // do k+1 as its not 0-based 

        // base case: if(k == 0 | i == n)   return 0
        for(int i = 0; i <= n; i++) {
            dp[i][0][0] = 0;    // 2nd parameter is of flag
            dp[i][1][0] = 0;
        }

        // now set 0 for every flag & k, where i = n
        for(int j = 0; j <= k; j++) {
            dp[n][0][j] = 0;
            dp[n][1][j] = 0;
        }


        for(int i = n-1; i >= 0; i--) {
            for(int j = 0; j <= 1; j++) {
                for(int limit = 1; limit <= k; limit++) {       // k = 0 & i = n already done in base case
                    // copy recurrance:

                    int buy = 0;    
                    int noBuy = 0;

                    if(j == 1) {  
                        buy = max(   dp[i+1][false][limit] - prices[i],   
                                     dp[i+1][true][limit]               
                                );
                    }
                    else {
                        noBuy = max(   prices[i] + dp[i+1][true][limit-1],
                                               0 + dp[i+1][false][limit]                     // don't sell today & wait for other days
                                );
                    }

                    dp[i][j][limit] = max(buy, noBuy);
                }
            }
        }

        // return same state as made in initial call on recursion
        return dp[0][true][k];
    }
};