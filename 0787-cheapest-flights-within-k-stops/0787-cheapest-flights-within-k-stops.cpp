class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // a normal BFS can also work, don't need for Min Heap, 
        // its just normal BFS and testing the stops at every level and
        // updation of prices like Dijkstra's, it will be similar as previous solution
        // coz there aslo we use min heap sorted on stops, so here in normal BFS queue
        // we go stop-wise so the earlier stops get prioritised!

        // store {dest, price}
        vector<vector<pair<int, int>>> adj(n);
        for(int i = 0; i < flights.size(); i++) {
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }

        // works like dist array of Dijkstra's algo
        vector<int> prices(n, INT_MAX);
        prices[src] = 0;

        // [priceToReach, from] 
        queue<vector<int>> q;
        q.push({0, src});

        int stops = 0;      // increase stops after each level pass

        // don't cross the limit of allowed stops
        while(!q.empty() && stops <= k) {
            int sz = q.size();

            while(sz--) {
                int totalPrice = q.front()[0];
                int from = q.front()[1];
                q.pop();

                // don't need to explore paths going from destination, final stop is destination
                if(from == dst)
                    continue;       

                for(auto to: adj[from]) {
                    int dest = to.first;
                    int fare = to.second;

                    if(prices[dest] > totalPrice + fare) {
                        prices[dest] = totalPrice + fare;
                        q.push({prices[dest], dest});
                    }
                }
            }

            stops++;
        }

        return prices[dst] == INT_MAX ? -1  : prices[dst];
    }
};