class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        // its simple BFS traversal just ignore the nodes which are in restricted set
        // need to create adjacency list for traversal

        vector<vector<int>> adj(n);

        for(auto it: edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        // put the restricted nodes in seen as we can't traverse then
        unordered_set<int> seen(restricted.begin(), restricted.end());
        queue<int> q;

        seen.insert(0);
        q.push(0);

        int rechable = 0;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            rechable++;

            for(int u: adj[node]) {
                if(!seen.count(u)) {
                    q.push(u);
                    seen.insert(u);
                }
            }
        }

        return rechable;
    }
};