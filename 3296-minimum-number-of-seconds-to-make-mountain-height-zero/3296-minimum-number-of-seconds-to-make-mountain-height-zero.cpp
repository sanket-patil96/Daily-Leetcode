class Solution {
public:
    typedef long long ll;
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        // using min heap
        
        // {maxTimeWorked, baseWork, timeReduced}
        priority_queue<vector<ll>, vector<vector<ll>>, greater<>> pq;

        for(auto i: workerTimes) {
            pq.push({i, i, 1});
        }

        ll ans = 0;

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            ll maxTimeWorked = it[0];
            ll baseTime = it[1];
            ll reducedHeight = it[2];

            ans = max(ans, maxTimeWorked);

            // in every iteration worker reduces Only 1 unit of height from mountain
            mountainHeight--;

            if(mountainHeight == 0)
                break;

            // update the data for the current worker
            ll nextHeight = reducedHeight + 1;
            ll nextTimeWorked = maxTimeWorked +  (baseTime * nextHeight);
            pq.push({nextTimeWorked, baseTime, nextHeight});
        }

        return ans;
    }
};