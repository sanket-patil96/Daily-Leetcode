class Solution {
private:
    int dir[5] = {-1, 0, 1, 0, -1};  // to get neighbouring cells (ith is for row i+th is for col run i = 0 -> i < 4 for 4 directions up, right, down, left)

public:

    bool isSafe(int r, int c, vector<vector<int>>& grid) {
        if(r < 0 || r >= grid.size() || c < 0 || c >= grid.size())
            return false;
        return true;
    }

    void dfs(int r, int c, queue<pair<int, int>> &q, vector<vector<int>>& grid) {
        // mark as visited & push in queue
        grid[r][c] = 2;
        q.push({r, c});

        // visit neighbouring land
        for(int i = 0; i < 4; i++) {
            int newR = r+dir[i];
            int newC = c+dir[i+1];
            if(isSafe(newR, newC, grid) && grid[newR][newC] == 1)
                dfs(newR, newC, q, grid);
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        // 1. store any 1 island in queue for BFS & change its value to 2 so it wont apper when finding other island '1'
        // 2. Multi-source BFS on first island and try to find the min flips for finding 2nd island

        // will store {row, col} of island
        // we don't require to use priority queue here coz we go level-wise to count the closest route to reach 2nd island
        queue<pair<int, int>> q;

        for(int i = 0; i < grid.size(); i++) {
            bool flag = false;

            for(int j = 0; j < grid.size(); j++) {
                if(grid[i][j] == 1) {
                    dfs(i, j, q, grid);
                    flag = true;
                    break;              // as there are only 2 island's so stop when we process 1 island don't push other islnad's land in q
                }
            }

            if(flag)        // indicates 1 island is already pushed so stop looping
                break;
        }

        // start multi-source BFS
        int minFlips = 0;

        while(!q.empty()) {
            int sz = q.size();
            
            for(int i = 0; i < sz; i++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                // push neighbouring water cells
                for(int j = 0; j < 4; j++) {
                    int newR = r+dir[j];
                    int newC = c+dir[j+1];


                    if(isSafe(newR, newC, grid)) {
                        if(grid[newR][newC] == 1) 
                            return minFlips;

                        if(grid[newR][newC] == 0) {  // push only water cells
                            // cout << " hello";
                            grid[newR][newC] = 2;    // mark visited water cells
                            q.push({newR, newC});
                        }
                    }
                }

            }
            
            // consider in this level iterating we did 1 flip of  water cell
            minFlips++;
        }

        return -1;
    }
};