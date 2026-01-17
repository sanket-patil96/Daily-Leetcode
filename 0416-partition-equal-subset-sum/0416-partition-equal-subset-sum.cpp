class Solution {
public:

    bool canPartition(vector<int>& nums) {
        // tabulation same as subset sub (GFG): 
        
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        // if sum is odd then we can't break array into 2 parts for same sum
        if(sum % 2 != 0)    
            return false;

        int target = sum/2;

        // use tabulation, T/C: O(N*Target)  space:O(N*target)
        // changing states are 2, index & target, i can go upto n, target is 0 to target
        vector<vector<bool>> dp(n+1, vector<bool> (target+1, false));

        // base case creation
        // where target become 0
        for(int i = 0; i < n; i++)
            dp[i][0] = true;

        // 2nd case: only true when last element is equal target (if nums[0] <= target)
        if(nums[0] <= target)
            dp[0][nums[0]] = true;
        
        // convert states into loops
        for(int i = 1; i < n; i++) {
            for(int k = 1; k <= target; k++) {
                // copy recurance
                bool noTake = dp[i-1][k];
                bool take = false;
                
                if(nums[i] <= k)
                    take = dp[i-1][k - nums[i]];

                dp[i][k] = (take || noTake);
            }
        }

        return dp[n-1][target];
    }
};