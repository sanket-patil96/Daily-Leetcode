class Solution {
private: 
    int dir[5] = {-1, 0, 1, 0, -1};     // for getting 4 adjacent directions

public:
    bool containsCycle(vector<vector<char>>& grid) {
        // we can use DFS & mark in-path coordinates as '0', and if the current cell is not the 
        // "parent cell" and already visited(marked with '0') then it must be a cycle

        // if the path of dfs doesn't lead to cycle then all cells from that path, mark with something like '#' so 
        // we don't start DFS again from that cells

        int n = grid.size();
        int m = grid[0].size();

        // starting point can be from any cell so, have to check all cells
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] != '#' && solve(i, j, -1, -1, grid[i][j], grid))      // (-1, -1) = (pr & pc) stands for parent-row & parent-col
                    return true;
            }
        }

        return false; 
    }

    bool solve(int r,  int c, int pr, int pc, char original, vector<vector<char>> &grid) {
        if(r >= grid.size() || r < 0 || c >= grid[0].size() || c < 0)
            return false;

        if(grid[r][c] == '#') return false;
        
        // if current cell already visited & its not the parent cell means there must be cycle in the current path!
        if(grid[r][c] == '0') return true;

        // it should only check after above line, coz we had changed grid[i][j] so it won't be same as original, so it will always return false, so  need to check above condition if its cycle
        if(grid[r][c] != original) return false;

        grid[r][c] = '0';       // mark as visited in 'current path'

        // traverse to the 4 directions
        for(int i = 0; i < 4; i++) {
            int newR = r + dir[i];
            int newC = c + dir[i+1];
            
            if(newR == pr && newC == pc) continue;
            
            if(solve(newR, newC, r, c, original, grid))
                return true;
        }

        grid[r][c] = '#';   // permanently mark processed cell

        return false;
    }
};