class Solution {
public:

    int cherryPickup(vector<vector<int>>& grid) {
        // space optimization:
        // 3D DP can be space optimised to 2D DP

        // as here as we can see dp[i+1][j1+dj1][j2+dj2] we just require the next row every time
        // so we can avoid the use of array for `row`

        int n = grid.size(); 
        int m = grid[0].size();

        // DP[M][M]
        vector<vector<int>> nextRow(m, vector<int> (m, 0));
        vector<vector<int>> temp(m, vector<int> (m, 0));

        // base case
        for(int j1 = 0; j1 < m; j1++) {
            for(int j2 = 0; j2 < m; j2++) {
                if(j1 == j2)  nextRow[j1][j2] = grid[n-1][j1];
                else          nextRow[j1][j2] = grid[n-1][j1] + grid[n-1][j2];
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
                                currSum += nextRow[j1+dj1][j2+dj2];
                            else 
                                currSum += -1e8;        // adding -ve so it won't get accepted
                            
                            maxCherry = max(maxCherry, currSum);      // row can be only +1
                        }
                    }

                    temp[j1][j2] = maxCherry;
                }
            }

            nextRow = temp;  
        }

        return nextRow[0][m-1];
    }
};