class Solution {
private: 
    // for up, right, down, left, use: current ind = row, & next ind = col
    int dist[5] = {-1, 0, 1, 0, -1};

public:

    void dfs(int r, int c, int n, int m, vector<vector<int>>& grid) {
        if(r < 0 || c < 0 || r >= n || c >= m || grid[r][c] != 1)
            return;

        // mark it as visited
        grid[r][c] = 2;

        // travel to neighbouring cells
        for(int i = 0; i < 4; i++)
            dfs(r+dist[i], c+dist[i+1], n, m, grid);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        // we apply flood fill from boundry cells
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;

        // mark boundry connected cells as 2 & flood fill till we found as much land
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) 
                if((i*j == 0 || i == n-1 || j == m-1) && grid[i][j] == 1)
                    dfs(i, j, n, m, grid);      // all boundries covered
    

        // check cells which has 1 , means boundry cells doesn't reach to them
        int count = 0;
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) 
                if (grid[i][j] == 1) count++;

        return count;
    }
};