class Solution {
public:
    bool isSafe(int r, int c, int n, vector<vector<int>>& grid) {
        if(r >= n || c >= n || r < 0 || c < 0 || grid[r][c] == 1)   
            return false;
        return true;
    }

    int maxDistance(vector<vector<int>>& grid) {
        // we have to start bfs from each land (Multi-source BFS)
        // we first put all the land cells(1) in queue & start bfs from that 
        // for each adjacent water of land add+1 distance from current cell as its going 'more far' from land, only if when its not visited cell
        // if water cell already visited means there is already shorter distance land from that water cell
        // so we get the maximum dist of land from all the water cell

        // if dist = 0 means there is no water/land cell
        // q contains {{row, col}, dist}
        queue<pair<pair<int, int>, int>> q;
        int n = grid.size();

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == 1)
                    q.push({{i, j}, 0});            // starting distance from land is always 0

        // if there is no land 
        if(q.empty())
            return -1;

        vector<vector<int>> vis(n, vector<int> (n, 0));
        
        int maxDist = INT_MIN;
        int DIST[] = {0, -1, 0, 1, 0};         // curr ind(row) add with next index(col) till ind 3 (for left, up, right, down)

        while(!q.empty()) {
            pair<int, int> node = q.front().first;
            int dist = q.front().second;
            q.pop();

            maxDist = max(maxDist, dist);

            // start checking nearby cells if water
            for(int i = 0; i < 4; i++) {
                int r = node.first + DIST[i];
                int c = node.second + DIST[i+1];

                if(isSafe(r, c, n, grid) && !vis[r][c]) {
                    q.push({{r, c}, dist+1});
                    vis[r][c] = 1;
                }
            }
        }

        // maxDist == 0 indicates there is only land in grid, so its not incremented
        return maxDist == 0 ? -1 : maxDist;
    }
};