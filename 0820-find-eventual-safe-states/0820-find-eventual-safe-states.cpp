class Solution {
public:
    bool dfs(int node, vector<bool> &vis, unordered_set<int> &unsafe, set<int> &safe, vector<vector<int>> &adj) {
        if(unsafe.find(node) != unsafe.end())
            return false;

        vis[node] = true;

        bool flag = true;       // to indicate not all adjacent path lead to safe state
        for(auto v: adj[node]) {   
            // if the current adjacent is already safe then check further adjacents
            // this check require before next check, coz there we having condition that has vis[v]
            // so even the adjacent is safe it will be visited and eventualy lead to make it flag = false
            if(safe.find(v) != safe.end())  
                continue;

            if(vis[v] || !dfs(v, vis, unsafe, safe, adj)) {
                flag = false;
                break;          // current node can't be safe so break furtehr checks
            }
        }
        

        if(!flag) {
            unsafe.insert(node);
            return false;
        }
        else {
            safe.insert(node);
            return true;
        }
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // we have to maintain 2 sets for unsafeNode & safeNode
        // if adjacent of node is in unsafe set then the current node  also becomes unsafe
        // coz, every adjacent path should  lead to terminal node(or safe node) to make current node safe
        // So, return true if on all paths from current node are safe & put the node in safe node

        // if graph have cycle then also set as unsafe exp: [[1],[2],[0, 3],[]]  here 
        // it has cycle from node 2-1 but 2 also go on terminal node 3 but it given that it has only [3] as safe node

        int n = graph.size();
        unordered_set<int> unsafe;
        set<int> safe;           // used as answer
        vector<bool> vis(n, false);

        for(int i = 0; i < n; i++) 
            if(!vis[i] && unsafe.find(i) == unsafe.end()) 
                dfs(i, vis, unsafe, safe, graph);
        

        vector<int> ans;
        for(auto i: safe)
            ans.push_back(i);
        return ans;
    }
    
};