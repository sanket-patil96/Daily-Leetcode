class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // there are some choices related with each step, so we can solve it recursively

        // as we only using single next array, we can optimise it to 1 1D array

        // need dp size [2]

        int n = prices.size();
        vector<int> dp(2, 0);

        // base case: i == n; return 0 for every column
        dp[0] = 0;
        dp[1] = 0;

        for(int i = n-1; i >= 0; i--) {
            for(int j = 0; j <= 1; j++) {
                // copy the recurrance:

                int profit = 0;

                if(j == 1) {
                    profit = max(  dp[false] - prices[i],
                                   dp[true]
                            );
                }

                // agian 2 way for selling on current day, either sell today or go to next days
                else  {
                    profit = max(  prices[i] + dp[true],
                                    0 + dp[false]
                                );
                }

                // we can update it directly on same row as we looping from reverse for row & accesing results from right of array
                dp[j] = profit;
            }
        }

        // answer will remain on first last cell of first row (as we started from n and goes till 0 for rows, & 0 to 1 for column)
        return dp[1];
    }
};