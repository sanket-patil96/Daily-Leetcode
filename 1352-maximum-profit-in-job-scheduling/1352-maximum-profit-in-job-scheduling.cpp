class Solution {
public:

    int binary_search(vector<vector<int>> &events, int target) {
        int left = 0;
        int right = events.size();

        while(left < right) {
            int mid = (left + right) / 2;
						
						// we can't even start next event on same day as previous event ends on.
            if(events[mid][0] < target)
                left = mid+1;
            else 
                right = mid;
        }

        return left;
    }

    int dfs(int curr_ind,  vector<vector<int>> &events, vector<int> &dp) {
        if(curr_ind == events.size())
            return 0;

        // next available event after selecting current event
        int next_ind = binary_search(events, events[curr_ind][1]);

        if(dp[curr_ind] != -1)
            return dp[curr_ind];

        // get max profit by choosing it OR not choosing it
        dp[curr_ind] = max(dfs(curr_ind+1, events, dp), 
                                dfs(next_ind, events, dp) + events[curr_ind][2]);

        return dp[curr_ind];
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        // same as problem 1751
        
        int n = startTime.size();

        // make it together  to better the operations
        vector<vector<int>> events;
        for(int i = 0; i < n; i++) {
            events.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(events.begin(), events.end());     // it will sort the event by start time

        // at max i can choose all events so 2d [cnt][event]
        vector<int> memo(n, -1);

        return dfs(0, events, memo);
    }
};