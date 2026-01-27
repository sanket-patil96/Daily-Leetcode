class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // convert to tabulation
        // define base case
        // convert states into loops
        // copy the recurrance

        int n = prices.size();
        vector<vector<vector<long>>> dp(n+1, vector<vector<long>> (2, vector<long>(3, 0)));

        // base case1: when limit == 0 return 0 for every row & col[0/1]
        for(int i = 0; i < n; i++) {
            dp[i][0][0] = 0;
            dp[i][1][0] = 0;
        }

        // case 2: for i == n; return 0, for every cols
        for(int j = 0; j <= 1; j++)
            for(int k = 0; k <= 2; k++) 
                dp[n][j][k] = 0;


        // states -> loop
        for(int i = n-1; i >= 0; i--) {                         // start from n-1, coz n is covered in base case
            for(int j = 0; j <= 1; j++) {
                for(int limit = 1; limit <= 2; limit++) {       // start from 1 as 0 is covered in base case
                    // copy the recurrance:

                    int profit = 0;
                    
                    if(j == 1) {
                        profit = max(  dp[i+1][false][limit] - prices[i],   // buy means, reduce it from the selling price to get profit
                                       dp[i+1][true][limit]
                                );
                    }

                    else  {
                        profit =  max(  prices[i] + dp[i+1][true][limit-1],
                                        0 + dp[i+1][false][limit]
                                    );
                    }

                    dp[i][j][limit] = profit;
                }
            }
        }

        // return last cell of first row, that where the last modified result got stored
        return dp[0][1][2];
    }
};