class Solution {
public:
    bool isSafe(int r, int c, int n, vector<vector<int>>& grid) {
        if(r < 0 || c < 0 || r >= n || c >= n || grid[r][c] == 1)
            return false;
        
        return true;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // we use simple single source BFS technique
        // mark 1 for visited cells, first one to reach destination is shortest path

        int n = grid.size();

        // base case
        if(grid[0][0] == 1)
            return -1;

        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});
        grid[0][0] = 1;     // mark as visited
        int minLen = INT_MAX;

        while(!q.empty()) {
            pair<int, int> cell = q.front().second;
            int len = q.front().first;
            q.pop();

            if(cell.first == n-1 && cell.second == n-1)
                minLen = min(minLen, len);

            // visit neighbours, (top-left, up, down, top-right, right, bottom-right, bottom, bottom-left, left)
            int row[] = {-1, -1, 0, 1, 1, 1, 0, -1};
            int col[] = {0, 1, 1, 1, 0, -1, -1, -1};
            for(int i = 0; i < 8; i++) {
                int newR = cell.first+row[i];
                int newC = cell.second+col[i];
                if(isSafe(newR, newC, n, grid)) {
                    grid[newR][newC] = 1;       // mark as visited
                    q.push({len+1, {newR, newC}});
                }
            }
        }

        return  minLen == INT_MAX ? -1 : minLen;
    }
};