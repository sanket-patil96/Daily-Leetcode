class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // this question can be boiled down to Partitions With Given Difference
        
        int n = nums.size();
        return countPartitions(n, target, nums);
    }

    int countPartitions(int n, int d, vector<int>& arr) {
        int total = accumulate(arr.begin(), arr.end(), 0);
        vector<vector<int>> dp(n, vector<int>(total + 1, -1));
        return solve(0, 0, total, dp, arr, d);
    }

    
    int solve(int i, int sum, int total, vector<vector<int>>& dp,
              vector<int>& arr, int diff) {
        if (i == arr.size()) {
            // this also ensures that, s1 sum > s2, coz diff is always positive
            if (diff == ((total - sum) - sum)) {
                // cout << total << " " << sum << " " << abs(total-sum-sum) <<
                // endl;
                return 1;
            }
            return 0;
        }

        if (dp[i][sum] != -1)
            return dp[i][sum];

        int take = solve(i + 1, sum + arr[i], total, dp, arr, diff);
        int noTake = solve(i + 1, sum, total, dp, arr, diff);

        return dp[i][sum] = (take + noTake);
    }
};