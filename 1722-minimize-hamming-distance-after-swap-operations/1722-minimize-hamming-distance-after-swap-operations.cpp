class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        // If A can swap with B, and B with C, they are all in the same Union.
        // They can mix and match however they want. We don't need to track the exact swaps.

        // lets create the graph with index as nodes & allowedSwaps[i] as an edge
        // then do dfs and count components:
        // 2. Find connected components (DFS / Union-Find)
        // 3. For each component:
        // Count frequency of values in source
        // Try to match with target
        // Reduce matches from frequency map
        // Example intuition

        // Component indices: [0,1,2]

        // source: [1,2,3]
        // target: [2,1,4]

        // Inside component:
        // source freq → {1:1, 2:1, 3:1}
        // match target:
        // 2 → found → remove
        // 1 → found → remove
        // 4 → not found

        // mismatch = 1
        // do this for each component!

        int n = source.size();

        vector<vector<int>> adj(n);
        for(int i = 0; i < allowedSwaps.size(); i++) {
            int u = allowedSwaps[i][0];
            int v = allowedSwaps[i][1];
            adj[u].push_back(v);        // create bidirectional graph
            adj[v].push_back(u);
        }

        vector<bool> vis(n, false);
        int ans = 0;

        // Step 2: Process each component
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                vector<int> comp;
                dfs(i, adj, vis, comp);

                // Step 3: count frequencies
                unordered_map<int, int> freq;

                for(int idx : comp) {
                    freq[source[idx]]++;
                }

                // Step 4: match target
                for(int idx : comp) {
                    if(freq[target[idx]] > 0) {
                        freq[target[idx]]--;   // matched
                    } else {
                        ans++;                 // mismatch
                    }
                }
            }
        }

        return ans;

    }

    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& comp) {
        vis[node] = true;
        comp.push_back(node);

        for(int nei : adj[node]) {
            if(!vis[nei]) {
                dfs(nei, adj, vis, comp);
            }
        }
    }
};