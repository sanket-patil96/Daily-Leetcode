class Solution {
public:
    int findUParent(int node, vector<int> &parent) {
        if(node == parent[node])
            return node;
        return parent[node] = findUParent(parent[node], parent);
    }

    void findUnion(int u, int v, vector<int> &rank, vector<int> &parent) {
        int ultp_u = findUParent(u, parent);
        int ultp_v = findUParent(v, parent);

        if(ultp_u == ultp_v)
            return;

        if(rank[ultp_u] < rank[ultp_v]) 
            parent[ultp_u] = ultp_v;
        else if(rank[ultp_u] > rank[ultp_v])
            parent[ultp_v] = ultp_u;
        else {
            parent[ultp_v] = ultp_u;
            rank[ultp_u]++;
        }
    }



    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // now try using Disjoint set

        // we find ultimate parents for all edges
        vector<int> parent(n);
        for(int i = 0; i < n; i++)
            parent[i] = i;

        vector<int> rank(n, 0);

        for(auto it: edges)
            findUnion(it[0], it[1], rank, parent);

        return (findUParent(source, parent) == findUParent(destination, parent));
    }
};