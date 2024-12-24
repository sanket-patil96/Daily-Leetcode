class Solution {
public:

    bool isSafe(int r, int c, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(r < 0 || r >= n || c < 0 || c >= m || grid[r][c] == 0 || grid[r][c] == 2)
            return false;

        return true;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        // we use BFS, as it goies to visit its neighbours first, then neighbour's neighbour's 
        //  ,... till end so it comes in minimum time:

        // space n*m for queues
        // time: n*m overall

        int n = grid.size();
        int m = grid[0].size();

        // queue contains {{row, col}, rottenTime}
        queue<pair<pair<int, int>, int>> q;

        for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) 
                if(grid[i][j] == 2) 
                    q.push({{i, j}, 0});        // rotten time for already rotten orange is 0 mins


        // WE WANT MINIMUM TIME, SO WE SET IT TO MINIMUM & UPDATE IT WITH THE LAST ROTTEN TOMATO TIMING
        int minTime = INT_MIN;
        
        // for getting neighbours, (up, down, left, right)
        int r[] = {-1, 1, 0, 0};
        int c[] = {0, 0, -1, +1};

        while(!q.empty()) {
            pair<pair<int, int>, int> node = q.front();
            int row = node.first.first;
            int col = node.first.second;
            int t = node.second;
            q.pop();

            // stores max time from all rotten orages burn time
            minTime = max(minTime, t);

            // now make its adjacents rotten
            for(int i = 0; i < 4; i++) {
                int newR = row + r[i];
                int newC = col + c[i];

                if(isSafe(newR, newC, grid)) {
                    grid[newR][newC] = 2;       // it becomes rotten now (works like visited  array)
                    q.push({{newR, newC}, t+1});
                }
            }
        }


        // now check if all oranges are rotten or not
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) 
                if(grid[i][j] == 1) 
                    return -1;
                
        // minTime doesn't change means all are already rotten
        return minTime == INT_MIN ? 0 : minTime;
    }
};