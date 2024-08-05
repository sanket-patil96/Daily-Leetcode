class Solution {
public:
    void DFS(int row, int col, vector<vector<char>>& grid) {
        // make current cell as visited 
        grid[row][col] = '0';

        // check in four directions if any adjacent 1 then convert to 0
        // up
        if(row-1 >= 0 && grid[row-1][col] == '1')
            DFS(row-1, col, grid);

        // down
        if(row+1 < grid.size() && grid[row+1][col] == '1')
            DFS(row+1, col, grid);
        
        // left 
        if(col-1 >= 0 && grid[row][col-1] == '1')
            DFS(row, col-1, grid);

        // right
        if(col+1 < grid[0].size() && grid[row][col+1] == '1')
            DFS(row, col+1, grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        // Essentially you want to traverse the matrix until you find a 1. 
        // Once you locate one (no pun intended) you essentially use flood fill to 
        // recursively "mark" any connected 1s (the rest of the island) by replacing 
        // them with zeros. If you do not want to mutate the given matrix, you can 
        // use a visited matrix.
        // T/C: O(N*M)  S/C: O(1)
        
        int islands = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    // make its adjacents '0' as visited & increment the islands count
                    islands++;
                    DFS(i, j, grid);
                }
            }
        }

        return islands;
    }
};