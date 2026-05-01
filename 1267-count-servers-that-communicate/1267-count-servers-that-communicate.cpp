class Solution {
public:

    int countServers(vector<vector<int>>& grid) {
        // 2nd optimised approach:
        // Space: O(m+n).This can be reduced to min(m,n).
        // Time: O(m*n).
        // Here n is the number of rows and m is the number of columns.

        // Observation:
        // For each server, the row or the column must have another server except the current one.
        // We can simply keep a count of servers in each row and column and use this information to get the result while traversing the grid.

        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> rows(n);
        vector<int> cols(m);

        for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) 
                if(grid[i][j])
                    rows[i]++, cols[j]++;
        
        int connected = 0;
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) 
                //Check if there are any other server except the current one in it's corresponding row OR column.
                if(grid[i][j] && (rows[i] > 1 || cols[j] > 1))    
                    connected++;       


        return connected;
    }
};