class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // add 1 to the first and last of nums as boundry baloons, so indexes dont' give out of bound errors
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n = nums.size();            // take new size of array

        // now use memoization:
        // changing parameters: i & j
        // range is 0-N for both, so dp[N][N]
        // save result before return 

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(1, n-2, nums, dp);     // pass the original start & end elements indexes
    }

    int solve(int i, int j, vector<int> &nums, vector<vector<int>> &dp) {
        if(i > j)   
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int maxi = INT_MIN;     

        // we can choose any balloon to burst at last, and get one sequence which gives max results
        // if kth balloon is last to burst means there are no ballon left from [i...j] so multiply [k] with [i-1] * [k] * [j+1]
        for(int k = i; k <= j; k++) {
            int coins = solve(i, k-1, nums, dp) + solve(k+1, j, nums, dp) + (nums[i-1] * nums[k] * nums[j+1]);
            maxi = max(maxi, coins);
        }

        return dp[i][j] = maxi;
    }
};