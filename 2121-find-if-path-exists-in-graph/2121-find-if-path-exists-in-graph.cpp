class Solution {
public:
    void dfs(int node, vector<bool> &vis, vector<vector<int>> &adj) {
        vis[node] = true;

        for(auto v: adj[node]) {
            if(!vis[v])
                dfs(v, vis, adj);
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // we can use DFS
        // if both found in same component then there is path from soruce to destination else false
        // create a adjacency list
        vector<vector<int>> adj(n);         // bidirectional

        for(auto i: edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        vector<bool> vis(n, false);
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs(i, vis, adj);

                if(vis[source] && vis[destination])
                    return true;

                // if any one of them got visited then there is no path that joints both
                if(vis[source] || vis[destination])
                    return false;
            }
        }


        return true;
    }
};