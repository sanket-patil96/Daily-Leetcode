class Solution {
private:
    vector<int> size, parent;

    int findUParent(int x) {
        if(parent[x] != x)
            parent[x] = findUParent(parent[x]);
        return parent[x];
    }

    void Union(int u, int v) {
        int ultp_u = findUParent(u);
        int ultp_v = findUParent(v);

        if(ultp_u == ultp_v) return;

        if(size[ultp_u] < size[ultp_v]) {
            parent[ultp_u] = ultp_v;
            size[ultp_v] += size[ultp_u];
        }
        else {
            parent[ultp_v] = ultp_u;
            size[ultp_u] += size[ultp_v];
        }
    }

public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        // now lets do this using union find

        int n = source.size();
        parent.resize(n);
        size.resize(n, 1);

        for(int i = 0; i < n; i++) 
            parent[i] = i;
        
        for (auto& pair : allowedSwaps) {
            Union(pair[0], pair[1]);
        }

        // Step 2: group indices by root
        unordered_map<int, vector<int>> groups;
        for(int i = 0; i < n; i++) {
            int root = findUParent(i);
            groups[root].push_back(i);
        }

        int ans = 0;

        // Step 3: process each group
        for(auto &g : groups) {
            unordered_map<int, int> freq;

            // count source values
            for(int idx : g.second) {
                freq[source[idx]]++;
            }

            // match with target
            for(int idx : g.second) {
                if(freq[target[idx]] > 0) {
                    freq[target[idx]]--;
                } else {
                    ans++;   // mismatch
                }
            }
        }

        return ans;
    }
};