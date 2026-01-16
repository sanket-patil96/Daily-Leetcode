class Solution {
public:

    int solve(int i, int j1, int j2, vector<vector<vector<int>>> &dp, vector<vector<int>>& grid) {
        // handle out of bound case
        if((i < 0 || i >= grid.size()) || 
           (j1 < 0 || j1 >= grid[0].size() || 
            j2 < 0 || j2 >= grid[0].size())
        )
            return -1e8;

        if(dp[i][j1][j2] != -1)
            return dp[i][j1][j2];

        // if its the on last row (only check 2nd robot, coz when 1 reaches then only 2 reach so 1st robot must be on last row already)
        if(i == grid.size()-1) {
            // if they both on same index then only count 1 time, else get sum
            if(j1 == j2)   // they move to new row at same time so, no need to check for similar row
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }

        // for every move of robot-1 there are 3 choices for robot-2
        int maxCherry = 0;

        // there are 3 choices on next row these are: prev col, same col, next col , so range is -1 to +1 for columns
        for(int k = -1; k <= 1; k++) {
            for(int l = -1; l <= 1; l++) {
                int currSum = 0;
                if(j1 == j2)   
                    currSum = grid[i][j1];
                else
                    currSum = grid[i][j1] + grid[i][j2];

                currSum += solve(i+1, j1+k, j2+l, dp, grid);
                maxCherry = max(maxCherry, currSum);      // row can be only +1
            }
        }

        return dp[i][j1][j2] = maxCherry;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        // since there are only 2 robots placed on grid, 
        // 1 robo's choice may affect other robot and it can give overall
        // wrong result at end

        // so we can't try plain recursion, so also need to consider the effect of robots,
        // try all possibilities with each robot and get the max possible result
        
        // now have to reduce time by adding memoization
        // changing parameters in recursion are- i(its common), j1, j2
        // so we require 3D DP, of size- i can go till N, j's can go till M
        // so N*M*M size dp

        int n = grid.size(); 
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m, -1)));

        return solve(0, 0, m-1, dp, grid);
    }
};