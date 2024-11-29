class Solution {
public:
    // standard DFS backtracking doesn't work here!!!
    // int solve(int t, int r, int c, int n, int m, vector<vector<int>>& grid, vector<vector<int>> vis) {
    //     if(r >= n || r < 0 || c >= m || c < 0 || grid[r][c] > t)
    //         return INT_MAX;
        
    //     if(r == n-1 && c == m-1)
    //         return t;

    //     // mark the current cell as visited
    //     // int val = grid[r][c];
    //     // grid[r][c] = INT_MAX;

    //     if(vis[r][c] <= t)
    //         return INT_MAX;

    //     vis[r][c] = t;

    //     t = max(t+1, grid[r][c]);

    //     // from this place we have 4 choices, either go left, right, up or down
    //     int left  = solve(t+1, r, c-1, n, m, grid, vis);
    //     int right = solve(t+1, r, c+1, n, m, grid, vis);
    //     int up    = solve(t+1, r-1, c, n, m, grid, vis);
    //     int down  = solve(t+1, r+1, c, n, m, grid, vis);

    //     // restore the value while backtracking
    //     // grid[r][c] = val;

    //     return min({left, right, up, down});
    // }

    #define p pair<int, int>
    
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if(grid[0][1] > 1 && grid[1][0] > 1) return -1;

        vector<p> directions = { {1,0}, {0,1}, {-1,0}, {0,-1} };

        vector<vector<int>> time(m, vector<int> (n, INT_MAX));
        time[0][0] = 0;

        priority_queue< p, vector<p>, greater<p> > pq;
        pq.push({0, 0}); // {time, cell}

        while(!pq.empty()){
            p top = pq.top();
            pq.pop();

            int curr_time = top.first;
            int row = top.second / n;
            int col = top.second % n;

            if(row == m-1 && col == n-1) return curr_time;

            // all adjacent cells
            for(auto &dir : directions){
                int nr = row + dir.first;
                int nc = col + dir.second;

                if( nr == -1 || nr == m || nc == -1 || nc == n ) continue;
                int new_time;
                int diff = grid[nr][nc] - curr_time;

                if(curr_time >= grid[nr][nc]) new_time = curr_time + 1;
                else if(diff % 2 == 1) new_time = grid[nr][nc];
                else new_time = grid[nr][nc] + 1;
                
                if(new_time < time[nr][nc]){
                    time[nr][nc] = new_time;
                    pq.push({new_time, nr*n + nc});
                }
            }
        }
        return -1;
    }
};