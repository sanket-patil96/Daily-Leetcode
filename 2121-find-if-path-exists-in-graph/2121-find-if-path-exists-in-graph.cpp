class Solution {
public:
    int findUParent(int node, vector<int> &parent) {
        if(node == parent[node])
            return node;
        return parent[node] = findUParent(parent[node], parent);
    }

    void findUnion(int u, int v, vector<int> &parent) {
        int ultp_u = findUParent(u, parent);
        int ultp_v = findUParent(v, parent);

        parent[ultp_v] = ultp_u;
    }



    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // now try using Disjoint set

        // we find ultimate parents for all edges
        vector<int> parent(n);
        for(int i = 0; i < n; i++)
            parent[i] = i;


        for(auto it: edges)
            findUnion(it[0], it[1], parent);

        return (findUParent(source, parent) == findUParent(destination, parent));
    }
};