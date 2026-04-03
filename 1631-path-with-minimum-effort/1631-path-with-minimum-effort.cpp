class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // we use dijkstra's algo to find the min abs Diff required to reach destination
        // different array will prune the unneccesory paths going into pq that already traveled with lesser difference

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> effort(n,  vector<int> (m, INT_MAX));
        effort[0][0] = 0;     // source require 0 different to reach

        // min heap sorted according to  difference: [diff, row, col]
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, 0, 0});

        int dist[] = {-1, 0, 1, 0, -1};      // to calculate up, left,  down, right with [i][i+1]

        while(!pq.empty()) {
            auto [diff, r, c] = pq.top();
            pq.pop();

            // stop exploring Because first time you reach destination = optimal (Dijkstra property)
            if(r == n-1 && c == m-1) return diff;

            // try 4 neighbours
            for(int i = 0; i < 4; i++) {
                int newR = r + dist[i];
                int newC = c + dist[i+1];

                // check only if its safe & not out-of-bound!
                if(newR >= 0 && newR < n && newC >= 0 && newC < m) {
                    int maxDiff = max(diff, abs(heights[r][c] - heights[newR][newC]));
                    if(effort[newR][newC] > maxDiff) {
                        effort[newR][newC] = maxDiff;
                        pq.push({maxDiff, newR,  newC});
                    }
                }
            }
        }
        
        return effort[n-1][m-1];
    }
};