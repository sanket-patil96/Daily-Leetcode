class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        // if there are n meetings then at max there can be n+1 gaps
        // store the gaps in array
        // max meetings we can slide are k, means we can combine k+1 gaps
        //      ex: ['G1' M1 'G2 G3' M2 'G4' M3] let G = gap number, if k = 2 we slide 1st and 2nd meeting then 
        //      then we get G1 G2 & G3 continious. i.e k+1 gaps can be combined
        // so create window of size k+1 and slide on gaps array, find the maximum gap we can found

        int n = startTime.size();
        vector<int> gaps(n+1);

        // store gaps
        gaps[0] = startTime[0];
        gaps[n] = eventTime - endTime[n-1];

        for(int i = 1; i < n; i++) {
            gaps[i] = startTime[i] - endTime[i-1];
        }

        // now slide through window size of k+1;
        int maxTime = 0;
        int sum = 0;
        for(int i = 0;  i <= k; i++)
            sum += gaps[i];
        
        maxTime = max(maxTime, sum);
        for(int i = k+1;  i <= n; i++) {
            sum -= gaps[i-k-1];     // (remove out of window gap, -1 for 0-based indexing
            sum += gaps[i];
            maxTime = max(maxTime, sum);
        }
        
        return maxTime;
    }
};