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
        bool flag = false;
        for(int i = 0; i < 4; i++)
            dfs(r+dist[i], c+dist[i+1], n, m, grid);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        // we apply flood fill from boundry cells
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;

        // for first column 
        for(int i = 0; i < n; i++) 
            if(grid[i][0] == 1)
                dfs(i, 0, n, m, grid);
        
        // for first row
        for(int i = 0; i < m; i++) 
            if(grid[0][i] == 1)
                dfs(0, i, n, m, grid);

        // for last column 
        for(int i = 0; i < n; i++)
            if(grid[i][m-1] == 1)
                dfs(i, m-1, n, m, grid);
        
        // for last row 
        for(int i = 0; i < m; i++) 
            if(grid[n-1][i] == 1)
                dfs(n-1, i, n, m, grid);
        
        
        // check cells which has 1 , means boundry cells doesn't reach to them
        int count = 0;
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) 
                if (grid[i][j] == 1) count++;

        return count;
    }
};