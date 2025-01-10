class Solution {
private:
    int mod = 1000000007;
public:
    int solve(int n, vector<vector<pair<int, int>>> &adj) {
        
        vector<long> dist(n, LONG_MAX);  
        
        // now create queue containing {timeSignalReceived, node}
        priority_queue<pair<long, long>, vector<pair<long, long>>, greater<>> q;
        q.push({0, 0});         // signal receiving time for source is always 0
        dist[0] = 0;

        // Ways array
        vector<long> ways(n, 0);
        ways[0] = 1;  // Only one way to start at the source


        while (!q.empty()) {
            int d = q.top().first;
            int node = q.top().second;
            q.pop();

            // Ignore outdated entries in the priority queue
            if (d > dist[node]) continue;

            for (auto &v : adj[node]) {
                int time = v.first;
                int nextNode = v.second;

                // Relaxation step
                if (dist[nextNode] > dist[node] + time) {
                    dist[nextNode] = dist[node] + time;
                    q.push({dist[nextNode], nextNode});
                    ways[nextNode] = ways[node];  // Update ways for a shorter path
                } else if (dist[nextNode] == dist[node] + time) {
                    // If another shortest path is found, add the ways
                    ways[nextNode] = (ways[nextNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n-1];
    }



    int countPaths(int n, vector<vector<int>>& roads) {
        // lets use single Dijkstras Algo & find ways at same time

        // adjancy structure: [[{time, adj-node}], [{}],...]
        vector<vector<pair<int, int>>> adj(n);   // n+1 since the graph having 1-based nodes


        // build graph
        for (const auto &road : roads) {
            adj[road[0]].emplace_back(road[2], road[1]);
            adj[road[1]].emplace_back(road[2], road[0]);
        }

        int shortestRoute = solve(n, adj);
        return shortestRoute;
    }
};