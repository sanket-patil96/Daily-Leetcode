class Solution {
public:

    int solve(int i, int j1, int j2, vector<vector<vector<int>>> &dp, vector<vector<int>>& grid) {
        // handle out of bound case
        if(j1 < 0 || j1 >= grid[0].size() || j2 < 0 || j2 >= grid[0].size())
            return -1e8;


        // if its the on last row (only check 2nd robot, coz when 1 reaches then only 2 reach so 1st robot must be on last row already)
        if(i == grid.size()-1) {
            // if they both on same index then only count 1 time, else get sum
            // they move to new row at same time so, no need to check for similar row
            if(j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }

        if(dp[i][j1][j2] != -1)
            return dp[i][j1][j2];

        // for every move of robot-1 there are 3 choices for robot-2
        int maxCherry = 0;

        // simulteniously explore all paths for both robots
        // there are 3 choices on next row these are: prev col, same col, next col , so range is -1 to +1 for columns
        for(int k = -1; k <= 1; k++) {
            for(int l = -1; l <= 1; l++) {
                int currSum = 0;

                if(j1 == j2) currSum = grid[i][j1];
                else currSum = grid[i][j1] + grid[i][j2];

                currSum += solve(i+1, j1+k, j2+l, dp, grid);
                maxCherry = max(maxCherry, currSum);      // row can be only +1
            }
        }

        return dp[i][j1][j2] = maxCherry;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        // using tabulation:

        // define base case
        // express everything in tern of for loops (loops of i, j1, j2)
        // copy the recurrance

        int n = grid.size(); 
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m, 0)));

        // base case
        for(int j1 = 0; j1 < m; j1++) {
            for(int j2 = 0; j2 < m; j2++) {
                if(j1 == j2)  dp[n-1][j1][j2] = grid[n-1][j1];
                else          dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }

        // express in term of loops
        for(int i = n-2; i >= 0; i--) {
            for(int j1 = 0; j1 < m; j1++) {
                for(int j2 = 0; j2 < m; j2++) {
                    // copy the recurrance

                    int maxCherry = -1e8;

                    for(int dj1 = -1; dj1 <= 1; dj1++) {
                        for(int dj2 = -1; dj2 <= 1; dj2++) {
                            int currSum = 0;

                            if(j1 == j2) currSum = grid[i][j1];
                            else currSum =         grid[i][j1] + grid[i][j2];

                            if(j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m)
                                currSum += dp[i+1][j1+dj1][j2+dj2];
                            else 
                                currSum += -1e8;        // adding -ve so it won't get accepted
                            
                            maxCherry = max(maxCherry, currSum);      // row can be only +1
                        }
                    }

                    dp[i][j1][j2] = maxCherry;
                }
            }   
        }

        return dp[0][0][m-1];
    }
};