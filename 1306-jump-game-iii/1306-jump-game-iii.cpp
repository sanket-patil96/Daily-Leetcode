class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        // we use BFS to push the next and previous indexes in queue
        // if we found any 0 value then return true
        // else  keep pushing untill in-bound & !pq.empty()

        int cnt = count(arr.begin(), arr.end(), 0);
        if(cnt == 0)
            return false;

        priority_queue<int> pq;
        vector<int> seen(arr.size(), 0);

        pq.push(start);
        seen[start] = 1;

        int n = arr.size();

        while(!pq.empty()) {
            int ind = pq.top();
            pq.pop();

            if(arr[ind] == 0)   return true;

            int nextInd = ind + arr[ind];
            int prevInd = ind - arr[ind];

            if(nextInd < n && !seen[nextInd]) {
                seen[nextInd] = 1;
                pq.push(nextInd);
            }
            if(prevInd >= 0 && !seen[prevInd]) {
                seen[prevInd] = 1;
                pq.push(prevInd);
            }
        }

        return false;
    }
};