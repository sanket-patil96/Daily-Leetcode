class Solution {
private:
    int unconnected = 0;    // total no of unconnected servers

public:
    void dfs(int r, int c, vector<vector<int>>& vis, vector<vector<int>>& grid) {
        vis[r][c] = 1;

        bool flag = false;      // to find if current server is connected to someone (other than itself)
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1 && (r == i || c == j)) { // if it matches to any row OR col then connected
                    if(vis[i][j] == 0)
                        dfs(i, j, vis, grid);

                    // means current server atleast connected to any one (doesn't matter its if visited & it should not the match to itself)
                    if(!(i == r && j == c))
                        flag = true;                // state that the current server is connected to any server
                }
            }
        }

        // after checking all the servers it doens't got any connected server then its seperate server
        if(!flag)
            unconnected++;
    }

    int countServers(vector<vector<int>>& grid) {
        // i think it can be variation of the problem: most stones removal
        // we have to count the unconnected components & return the totalServers-unconnected count
        // a server is connected only if its row or col matches to any other
        // so we do dfs on grid & visit all servers if they match to same row OR col to current server

        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int> (m));
        int servers = 0;            // count the total servers

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    servers++;  
                    if(vis[i][j] == 0) {
                        cout << i << " " << j << endl;
                        dfs(i, j, vis, grid);
                    }
                }
            }
        }

        return servers-unconnected;
    }
};