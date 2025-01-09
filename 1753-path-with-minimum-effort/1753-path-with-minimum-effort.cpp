class Solution {
public:
    bool isSafe(int r, int c, int n, int m, vector<vector<int>>& grid) {
        if(r < 0 || c < 0 || r >= n || c >= m)
            return false;
        
        return true;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        // time & space: O(n^2)
        // we use simple Dijkstrs's Algorithm that will be us the min-effort require to reach the destination, after all possible checks
        // keep a visited array, mark 1 for visited cells
        // make another array for storing min distances
        // IMP: the min-distance for current cell is the "MAX" distance from (curr effort = height[parent] - height[curruent], maxEffort of this path)

        int n = heights.size();
        int m = heights[0].size();

        // base case: if we already at destination, ex: [[1]] then no efforts required
        if(0 == n-1 && 0 == m-1)
            return 0;

        // initially all cell will have infinite efforts
        vector<vector<int>> effort(n, vector<int> (m, INT_MAX));
        effort[0][0] = 0;     // for reaching sorce its 0 efforts, already we are there
        
        // queue will store the absolute difference of current cell with coordinates
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, 0}});    // source with 0 efforts


        // visit neighbours, up, right, down, left, treat i as row, & i+1 as col)
        int dist[] = {-1, 0, 1, 0, -1};

        while(!q.empty()) {
            pair<int, int> cell = q.front().second;
            int currEffort = q.front().first;
            q.pop();

            // if(cell.first == n-1 && cell.second == n-1)
            //     minLen = min(minLen, len);

            for(int i = 0; i < 4; i++) {
                int newR = cell.first+dist[i];
                int newC = cell.second+dist[i+1];

                if(isSafe(newR, newC, n, m, heights)) {
                    int newEffort = abs(heights[newR][newC] - heights[cell.first][cell.second]);
                    
                    // should store max effort till current cell
                    int maxEffort = max(currEffort, newEffort);

                    // update efforts grid
                    if(effort[newR][newC] > maxEffort) {
                        effort[newR][newC] = maxEffort;
                        q.push({maxEffort, {newR, newC}});
                    }
                }
            }
        }

        // return the destination effort from efforts array
        return  effort[n-1][m-1];
    }
};