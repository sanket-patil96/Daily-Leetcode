class Solution {
public:

    void dfs(int node, vector<int> &vis, int n, vector<vector<int>>& adj) {

        vis[node] = 1;

        // visit the connected computers to current computer
        for(int it: adj[node]) {
            if(!vis[it])
                dfs(it, vis, n, adj);
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        // you just need two things .
        // n-1>connections.length return -1 (don't have enough edge to connect all)
        // find number of connected components , return count-1

        if(n-1 > connections.size())
            return -1;

        // we need to create adjacency list coz
        // connections variable represents the edges of the graph, not an adjacency list
        vector<vector<int>> adj(n);
        for(auto i: connections) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        vector<int> vis(n, 0);
        int connectedComponents = 0;

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs(i, vis, n, adj);
                connectedComponents++;
            }
        }

        return connectedComponents-1;
    }
};