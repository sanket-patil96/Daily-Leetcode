class Solution {
public:
    static bool cmpTime(const vector<int>& event, int time) {
        return event[0] < time;
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        // cleaner version to better understand my previous approach:

        sort(events.begin(), events.end());
        int n = events.size();

        vector<int> suffixMax(n);
        suffixMax[n-1] = events[n-1][2];        // use array coz events are already sorted, so use its index

        for(int i = n-2; i >= 0; i--) {
            suffixMax[i] = max(events[i][2], suffixMax[i+1]);
        }

        int maxVal = 0;

        for(int i = 0; i < n; i++) {
            int currVal = events[i][2];
            int currEnd = events[i][1];

            maxVal = max(maxVal, currVal);

            auto it = lower_bound(events.begin(), events.end(), currEnd + 1, cmpTime);
            if(it != events.end()) {
                int idx = it - events.begin();      // to get index from pointer
                maxVal = max(maxVal, currVal + suffixMax[idx]);
            }
        }
        
        return maxVal;
    }
};
