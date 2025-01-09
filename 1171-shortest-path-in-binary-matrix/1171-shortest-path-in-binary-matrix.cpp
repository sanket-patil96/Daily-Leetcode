class Solution {
public:
    bool isSafe(int r, int c, int n, vector<vector<int>>& grid) {
        if(r < 0 || c < 0 || r >= n || c >= n || grid[r][c] == 1)
            return false;
        
        return true;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // some improvements from previous approach, time & space: O(n^2)
        // we use simple single source BFS technique that visit cells 'level-by-level'
        // the first one to visit destination will be the shortest path, because of 'level-by-level' BFS
        // mark 1 for visited cells as soon as we see it

        int n = grid.size();

        // base cases
        if(grid[0][0] == 1)
            return -1;

        // if we already at destination, ex: [[0]]
        if(0 == n-1)
            return 1;

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;     // mark as visited
        int len = 1;        // coz currently we have source in path so length = 1

        // visit neighbours, (top-left, up, down, top-right, right, bottom-right, bottom, bottom-left, left)
        int row[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int col[] = {0, 1, 1, 1, 0, -1, -1, -1};

        while(!q.empty()) {

            int size = q.size();

            for(int j = 0; j < size; j++) {
                pair<int, int> cell = q.front();
                q.pop();
                
                for(int i = 0; i < 8; i++) {
                    int newR = cell.first+row[i];
                    int newC = cell.second+col[i];
                    if(isSafe(newR, newC, n, grid)) {
                        // this ensures that this is shortest path, coz this cell is first to reach here in this length
                        if(newR == n-1 && newC == n-1)
                            return len+1;       // +1 for current cell, we haven't add it, its done outside level

                        grid[newR][newC] = 1;       // mark as visited
                        q.push({newR, newC});
                    }
                }
            }

            // since level is complete increase the lenght of path, coz one of them will lead to shortest path
            len++;
        }

        // If we exhaust the queue without finding the path
        return -1;
    }
};