class Solution {
public:

    bool solve(vector<int> &nums, vector<vector<int>> &dp, int i, int target) {
        if(target == 0)
            return true;

        if(i == 0)    
            return nums[0] == target;       // so reducing with nums[0] target becomes 0

        if(dp[i][target] != -1)
            return dp[i][target];

        bool noTake = solve(nums, dp, i-1, target);
        bool take = false;
        
        if(nums[i] <= target)
            take = solve(nums, dp, i-1, target - nums[i]);

        return dp[i][target] = (take || noTake);
    }

    bool canPartition(vector<int>& nums) {
        // we have to make 2 parts, so we have to find the part which can give the sum half of total
        // get the sum of array
        // then apply take it or not logic on every element
        
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        // if sum is odd then we can't break array into 2 parts for same sum
        if(sum % 2 != 0)    
            return false;

        int target = sum/2;

        // use memoization to avoid overlapping sub-problems, T/C: O(N*Target)
        // changing states are 2, index & target, i can go upto n, target is 0 to target
        vector<vector<int>> dp(n+1, vector<int> (target+1, -1));

        return solve(nums, dp, n-1, target);
    }
};