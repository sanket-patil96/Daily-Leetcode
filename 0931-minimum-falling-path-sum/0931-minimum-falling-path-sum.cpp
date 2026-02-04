class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int mini = INT_MAX;

        vector<vector<int>> dp(n, vector<int> (m, INT_MIN));
        
        for(int j = 0; j < m; j++) 
            mini = min(mini, solve(0, j, n, m, matrix, dp));

        return mini;
    }

    int solve(int i, int j, int n, int m, vector<vector<int>>& matrix, vector<vector<int>> &dp) {
        if(j < 0 || j >= m)
            return 1e8;

         if(dp[i][j] != INT_MIN)
            return dp[i][j];

        // on last row we don't have chance to choose from next row, so return from here
        if(i == n - 1)
            return dp[i][j] = matrix[i][j];

        int sum = 1e8;

        // we have only 3 options to choose next col of next row
        for(int k = -1; k <= 1; k++) {
            sum = min(sum, solve(i+1, j+k, n, m, matrix, dp));
        }

        return dp[i][j] = (matrix[i][j] + sum);
    }
};