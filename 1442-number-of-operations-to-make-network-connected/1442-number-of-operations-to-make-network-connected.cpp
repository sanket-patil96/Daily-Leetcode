class Solution {
private:
    vector<int>  parent;

public:
    int findUPar(int node) {
        if(node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionSet(int u, int v) {
        // find ultimate parents of both
        int ult_pu = findUPar(u);
        int ult_pv = findUPar(v);

        if(ult_pu == ult_pv)
            return;

        parent[ult_pu] = ult_pv;
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        // basically we can say its version of (no.of islands)
        // you just need two things .
        // n-1>connections.length return -1 (don't have enough edge to connect all)
        // find number of connected components , return count-1
        // IF we want to connect 3 pc's then we only need 2 connections

        // we can also done this using DSU by finding how many computers have 
        // same ultimate parent, and ans-1 will be the required to make them connected

        if(n-1 > connections.size())
            return -1;

        parent.resize(n);
        for(int i = 0; i < n; i++)
            parent[i] = i;

        for(auto i: connections) {
            if(findUPar(i[0]) != findUPar(i[1])) {
                unionSet(i[0], i[1]);
                n--;
             }
        }
        
        // no of computers - unconnected clusters-1 (to join 2 pc's we need only 1 cable)
        return n-1;
    }
};