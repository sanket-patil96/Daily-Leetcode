class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // Step 1: Sort events by start day
        sort(events.begin(), events.end());

        priority_queue<int, vector<int>, greater<int>> minHeap;
        int day = 0, i = 0, n = events.size(), res = 0;

        // Process from day 1 to 100000 (maximum day possible)
        for (day = 1; day <= 100000; ++day) {
            // Step 2: Add all events starting today
            while (i < n && events[i][0] == day) {
                minHeap.push(events[i][1]); // store end days
                i++;
            }

            // Step 3: Remove expired events
            while (!minHeap.empty() && minHeap.top() < day) {
                minHeap.pop();
            }

            // Step 4: Attend the event that ends earliest
            if (!minHeap.empty()) {
                minHeap.pop();
                res++; // attended one event
            }

            // Optimization: break if all events are processed and heap is empty
            if (i == n && minHeap.empty()) break;
        }

        return res;
    }
};
