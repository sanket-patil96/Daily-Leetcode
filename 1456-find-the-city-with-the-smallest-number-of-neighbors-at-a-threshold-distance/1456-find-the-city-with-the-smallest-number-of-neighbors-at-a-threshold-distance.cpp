class Solution {
public:

    
    int dijkstra(int src, int n, vector<vector<pair<int, int>>> adj ,vector<int> &vis, int currDist, int maxDist) {
        // we require min heap which stores {dist, neighbour} (sorting accoding dist)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        pq.push({0, src});

        while(!pq.empty()) {
            int city = pq.top().second;
            int currDist = pq.top().first;
            pq.pop();

            if(dist[city] > currDist)
                dist[city] = currDist;

            for(auto v: adj[city]) {
                int cty = v.first;
                int distReq = v.second;         // distnace require to reach this city

                if(currDist + distReq < dist[cty] && (currDist+distReq) <= maxDist) {
                    pq.push({currDist+distReq, cty});
                }
            }
        }

        // try to visit cities with distance < maxDist
        int totalVisits = 0;
        for(auto i: dist)
            if(i <= maxDist)
                totalVisits++;

        // source city counts itself also so -1
        return totalVisits-1;
    }

    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // time: O(N * ElogV) where n is no of cities & ElogV is Dijkstra's Time complexity
        // for each city we check how much cities we can visit with given threshold
        // to do this, we use Dijkstra algorithm that will find min dist to reach each city from Source city
        // if dist < threshold then we can say we can visit that city
        // run dijkstra algo for each city as starting vertex

        // we make adjacency list of connected cities With their weights
        // adj contains [[{adjacentCity, weight}], ..] for each index city
        vector<vector<pair<int, int>>> adj(n);
        for(auto edge: edges) {
            int from = edge[0];
            int to = edge[1];
            int wt = edge[2];

            // graph is bidirectional, so set for both cities
            adj[from].push_back({to, wt});
            adj[to].push_back({from, wt});
        }

        int ansCity;
        int minVisitedCities = INT_MAX;
        
        for(int i = 0; i < n; i++) {
            vector<int> vis(n);
            int visitedCities = dijkstra(i, n, adj, vis, 0, distanceThreshold);
            if(visitedCities <= minVisitedCities) {
                minVisitedCities = visitedCities;
                ansCity = i;
            }
        }

        return ansCity;
    }
};