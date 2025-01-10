class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // USING distance array like dijkstra's algo
        // single source BFS will be sufficient here,
        // first have to create the adjacency list
        // then create q initially with having source node
        // and traverse till all nodes receive the signal

        // adjancy structure: [[{wt, adj-node}], [{}],...]
        vector<vector<pair<int, int>>> adj(n+1);   // n+1 since the graph having 1-based nodes

        vector<int> dist(n+1, INT_MAX);   // we have to ensure that all nodes gets visited, so keep visited array

        // build graph
        for(auto v: times)
            adj[v[0]].push_back({v[2], v[1]});      // directed graph
        
        // now create queue containing {timeSignalReceived, node}
        queue<pair<int, int>> q;
        q.push({0, k});         // signal receiving time for source is always 0
        dist[k] = 0;

        while(!q.empty()) {
            int node = q.front().second;
            int time = q.front().first;
            q.pop();

            // send signal to adjacent nodes & update the time
            for(auto v: adj[node]) {
                if(dist[v.second] > time+v.first) {
                    dist[v.second] = time+v.first;
                    q.push({time+v.first, v.second});
                }
            }
        }

        // edge case for disconnected compo, graph is 1-based indexed, so start from 1
        int minTime = INT_MIN;      // WE WANT the last time of node which received the signal at last, (means max value)
        for(int i = 1; i <= n; i++) {
            if(dist[i] == INT_MAX)      return -1;
            minTime = max(minTime, dist[i]);
        }

        return minTime;
    }
};