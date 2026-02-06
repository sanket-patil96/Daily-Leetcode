class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        // we can solve this using front partitioning pattern, that we used in Palindrome Partitioning II
        // max partition size can be from i to i+k, and withing this try to  create every partition
        // keep maxVal var for tracking maximum value in current partition
        // multiply it with its length of partition (j-i+1), so we get the sum of that partition
        // and call for f(i+1), 
        // return the maximum sum from all possibilities
        
        int n = arr.size();

        // lets memoize it:
        // changing parameters: i
        // create dp[N]

        vector<int> dp(n, -1);
        return solve(0, k, n, arr, dp);
    }

    int solve(int i, int k, int n, vector<int> &arr, vector<int> &dp) {
        if(i >= n)
            return 0;

        if(dp[i] != -1)
            return dp[i];

        long long maxSum = 0;
        int maxVal = arr[i];    // its the max value in current partition
        
        for(int j = i; j < min(n, i+k); j++) {
            maxVal = max(maxVal, arr[j]);
            int partitionLen = j-i + 1;     // +1 coz its 0 based indexing, & length is 1 based
            long long sum = ((long long)maxVal * partitionLen) + solve(j+1, k, n, arr, dp);
            maxSum = max(maxSum, sum);
        }

        return dp[i] = maxSum;
    }
};