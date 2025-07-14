class Solution {
private:
    int time = 1;

public:

    void dfs(int n, int parent, vector<vector<int>>& adj, vector<int> &tin,  vector<int> &low, vector<vector<int>> &ans) {
        tin[n] = time;
        low[n] = time;
        time++;

        for(auto u: adj[n]) {
            if(u == parent)     continue;

            // if not visited then visit and after its traversal complete take low time from u if its lower than parent node
            if(tin[u] == -1) {          
                dfs(u, n, adj, tin, low, ans);
                low[n] = min(low[n], low[u]);

                // now check if n--> u can be a critical or not, 
                // its critical connection connection if u can't reach out to n from other lower step
                if(tin[n] < low[u])
                    ans.push_back({n, u});
            }

            // if already visited then it can't be a critical connection, as it has other path's to reach out 
            // then only get the low time if possible
            else {
                low[n] = min(low[n], low[u]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // we only know if a connection can become critical if the adjacent node of parent node
        // can't reach out to parent from other paths
        // so we find if the node can reach to parent from any other path then it can't become critical connection

        // for this store the insertion time for all nodes
        // while traversing store the lowest step it can reach out
        // if insertion time of parent node  is less than lowest step its adjacenet reach out then its critical connection

        vector<vector<int>> adj(n);

        // first create the adjacency list
        for(auto i: connections) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        // now store time of insertion & low time(initially same as insertion time)
        vector<int>  tin(n, -1), low(n);
        vector<vector<int>> bridges;
        dfs(0, -1, adj, tin, low, bridges);

        return bridges;
    }
};