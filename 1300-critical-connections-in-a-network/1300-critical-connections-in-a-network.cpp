class Solution {
public:
    int timer = 1;

    void dfs(int node, int parent, vector<int> &vis, vector<int> adj[], int tin[],
    int low[], vector<vector<int>> &bridges)
    {
        // first mark node as visited
        vis[node] = 1;
        tin[node] = low[node] = timer;  //initialize at starting, it won't re-initialize after visited
        timer++;

        for(auto it: adj[node])
        {
            // as per algo don't check for parent node
            if(it == parent)    continue;

            if(!vis[it])
            {
                // traverse for adjacent 
                dfs(it, node, vis, adj, tin, low, bridges);

                // after child has complete its execution, first get lowest step it can reach from it
                low[node] = min(low[node], low[it]);

                // now check if [node--->it] can be bridge, if adjacent can't reach back to *node from another step
                // means we check how lowest step can adjacent reach if its greater than step require to reach 
                // parent then there's a bridge, (parent always comes before its adjacent it has insertion time)
                // so adjacent should have another path that can lead it to node's step
                if(tin[node] < low[it]) 
                    bridges.push_back({node, it});
            }
            else
            {
                // means node's current adjacent is already visited from another path so it can't be a bridge, so only update low if possible
                low[node] = min(low[node], low[it]);
            }

        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // Tarjan's Algorithm:
        // space: O(V + 2E) + O(3N) for vis, tin, low
        // time:  O(V + 2E) for dfs

        // we have to create adjacency list 
        // connections contain edges vector of vector where inner vector contains  node - edge
        vector<int> adj[n];
        for(auto it: connections)
        {
            // add edges both side coz undirected its Graph
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        // we require visited array for dfs traversal
        vector<int> vis(n, 0);
        int tin[n];         // time of insertion step in dfs 
        int low[n];
        vector<vector<int>> bridges;     // for storing answers

        dfs(0, -1, vis, adj, tin, low, bridges);
        return bridges;
    }
};