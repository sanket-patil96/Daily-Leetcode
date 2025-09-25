class Solution {
public:

    int binarySearch(int target, vector<vector<int>> &jobs) {
        int low = 0, high = jobs.size();

        while(low < high) {
            int mid = low + (high - low) / 2;

            // we can choose this job, but set mid to it so 
            if(jobs[mid][0] >= target) 
                high = mid;

            else
                low = mid+1;
        }

        return high;    // or low
    }

    int solve(int i, vector<vector<int>> &jobs, vector<int> &memo) {
        if(i == jobs.size())
            return 0;

        if(memo[i] != -1)
            return memo[i];

        // take the current Job 
        int nextJobInd = binarySearch(jobs[i][1], jobs);      // pass end time of current job for getting next job without overlaping dates
        int take = solve(nextJobInd, jobs, memo) + jobs[i][2];

        // don't take current Job
        int noTake = solve(i+1, jobs, memo);

        return memo[i] = max(take, noTake);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        // same as problem 1751
        
        // first store all the values in single unit according to jobs (i.e start, end & profit by jobs)
        vector<vector<int>> jobs;

        int n = startTime.size();
        for(int i = 0; i < n; i++)
            jobs.push_back({startTime[i], endTime[i], profit[i]});

        // sort jobs by start Time
        sort(jobs.begin(), jobs.end());

        vector<int> memo(n, -1);
        
        return solve(0, jobs, memo);
    }
};