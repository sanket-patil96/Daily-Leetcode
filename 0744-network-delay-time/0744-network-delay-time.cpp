class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // single source BFS will be sufficient here,
        // first have to create the adjacency list
        // then create q initially with having source node
        // and traverse till all nodes receive the signal

        // adjancy structure: [[{wt, adj-node}], [{}],...]
        vector<vector<pair<int, int>>> adj(n+1);   // n+1 since the graph having 1-based nodes

        vector<int> vis(n+1, 0);   // we have to ensure that all nodes gets visited, so keep visited array

        for(auto v: times)
            adj[v[0]].push_back({v[2], v[1]});      // directed graph
        
        // use priority queue to ensure it gives priority to the shortest weight path for each node & avoid long paths
        // now create queue containing {timeSignalReceived, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, k});         // signal receiving time for source is always 0

        int minTime = INT_MIN;      // WE WANT the last time of node which received the signal at last
        while(!q.empty()) {
            int node = q.top().second;
            int time = q.top().first;
            q.pop();

            // means node already visited from shortest path, coz of min-heap
            if(vis[node] == 1)  continue;

            minTime = max(minTime, time);
            vis[node] = 1;

            // send signal to adjacent nodes
            for(auto v: adj[node]) {
                q.push({time+v.first, v.second});
            }
        }

        // edge case for disconnected compo, graph is 1-based indexed, so start from 1
        for(int i = 1; i <= n; i++) 
            if(vis[i] == 0)
                return -1;

        return minTime;
    }
};