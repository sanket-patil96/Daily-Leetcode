class Solution {
public:

    bool isSafe(int r, int c, int m, int n, vector<vector<int>> &grid) {
        if(r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != 1)
            return false;

        return true;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        // store the minues and the row, col in min heap
        // get the top from heap and push its fresh tomatoes in heap with +1 minute increased
        // keep track of highest minute

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        // store all the rotten oranges at 0th minute
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    pq.push({0, {i, j}});
                }
            }
        }

        // perform multi-source BFS 
        int maxTime = 0;
        int dir[] = {-1, 0, 1, 0, -1};      // for adjacent cells

        while(!pq.empty()) {
            int time = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            maxTime = max(maxTime,  time);

            // rotten the adjacent fresh oranges
            for(int i = 0; i < 4; i++) {
                int newR = r+dir[i];
                int newC = c+dir[i+1];
                if(isSafe(newR, newC, m, n, grid)) {
                    pq.push({time+1, {newR, newC}});
                    grid[newR][newC] = 2;           // rotten the orange
                }
            }
        }   

        // check if any fresh orange remain in grid
        for(int i = 0; i < m; i++) 
            for(int j = 0; j < n; j++) 
                if(grid[i][j] == 1) 
                    return -1;

        return maxTime; 
    }
};