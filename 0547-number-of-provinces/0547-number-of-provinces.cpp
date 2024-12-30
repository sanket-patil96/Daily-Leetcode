class Solution {
private:
    vector<int> parent;
public:
    int findUParent(int node) {
        if(node == parent[node])
            return node;
        return parent[node] = findUParent(parent[node]);
    }

    void unionSet(int u, int v) {
        int ultp_u = findUParent(u);
        int ultp_v = findUParent(v);

        if(ultp_u == ultp_v)
            return;
        
        parent[ultp_u] = ultp_v;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        // we use Disjoint set to find & connect cities with their ultimate parents
        // and at last count the no.of unique ultimate parents for each city that will be our ansewr
        int n = isConnected.size();
        parent.resize(n);

        for(int i = 0; i < n; i++)
            parent[i] = i;

        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j)      continue;

                if(isConnected[i][j] == 1 && findUParent(i) != findUParent(j)) {
                    unionSet(i, j);
                    ans++;
                }
            }
        }

        // from total cities - connected clusters
        return n-ans;
    }
};