class Solution {
public:

    bool isSafe(int r, int c, vector<vector<int>> &vis, vector<vector<int>> &grid) {
        if(r >= grid.size() || c >= grid.size()  || r < 0 || c < 0 || vis[r][c]) 
            return false;

        return true;
    }

    void dfs(int r, int c, vector<vector<int>> &vis, vector<vector<int>> &grid, vector<vector<int>> &isLand) {
        if(!isSafe(r, c, vis, grid) || grid[r][c] == 0) 
            return;
        
        vis[r][c] = 1;
        isLand.push_back({r, c});

        // check on 4 directions
        int row[] = {1, -1, 0, 0};
        int col[] = {0, 0, 1, -1};
        for(int i = 0; i < 4; i++) {
            // if(!isSafe(r+row[i], c+col[i], vis, grid) || grid[r][c] != 0) 
            dfs(r+row[i], c+col[i], vis, grid, isLand);
        }
    }

    int bfs(vector<vector<int>>& island, vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int> (n, 0));

        // queue contains {{row, col}, bridge_length_for_current_point}
        queue<pair<pair<int, int>, int>> q;

        // mark the current island's positions as visited so they don't appear as nearer land
        // push the current land in queue
        for(auto it: island) {
            vis[it[0]][it[1]] = 1;
            q.push({{it[0], it[1]}, 0});        // 0 distance for soruce lands
        }

        int shortest_bridge = INT_MAX;

        while(!q.empty()) {
            pair<pair<int, int>, int> node = q.front();
            q.pop();

            int r = node.first.first;
            int c = node.first.second;
            int len = node.second;

            // push 0 adjacents (not neighbouring 1's)
            int row[] = {1, -1, 0, 0};
            int col[] = {0, 0, 1, -1};
            for(int i = 0; i < 4; i++) {
                int newR = r+row[i];
                int newC = c+col[i];
                if(isSafe(newR, newC, vis, grid)) {
                    if(grid[newR][newC] == 1) {
                        shortest_bridge = min(shortest_bridge, len);
                    }
                    else {
                        vis[newR][newC] = 1;
                        q.push({{newR, newC}, len+1});
                    }
                }
            }
        }

        return shortest_bridge;
    }

    int shortestBridge(vector<vector<int>>& grid) {
        // basic idea: 
        // store both islands (positions) using DFS & execute BFS for finding nearer '1'
        // on the island which has less land(less no.of 1's)

        int n = grid.size();
        vector<vector<int>> vis(n, vector<int> (n, 0));

        // array's to store the island's positions, useful for performing BFS on them
        vector<vector<int>> isLandOne;
        vector<vector<int>> isLandTwo;

        bool flag = true;       // means for first founded island('1') use the isLand1 & for 2nd land use isLandTwo
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] != 0 && !vis[i][j]) {
                    if(flag) {
                        dfs(i, j, vis, grid, isLandOne);
                        flag = false;       // needs only single time, coz there are only 2 islands
                    }
                    else 
                        dfs(i, j, vis, grid, isLandTwo);
                }
            }
        }

        // do BFS on the island which has less land
        int res = 0;
        if(isLandOne.size() < isLandTwo.size())
            res = bfs(isLandOne, grid);
        
        else 
            res = bfs(isLandTwo, grid);

        return res;
    }
};