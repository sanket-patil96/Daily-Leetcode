class Solution {
public:

    bool canPartition(vector<int>& nums) {
        // as we only using last row, we can space optimize it
        // space optimization: S/C: O(target)
        
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        // if sum is odd then we can't break array into 2 parts for same sum
        if(sum % 2 != 0)    
            return false;

        int target = sum/2;

        // use tabulation, T/C: O(N*Target)  space:O(N*target)
        // changing states are 2, index & target, i can go upto n, target is 0 to target
        vector<bool> dp(target+1, false);
        vector<bool> temp(target+1, false);
        
        // base case creation
        // where target become 0
        dp[0] = true;

        // 2nd base case: only true when last element is equal target (if nums[0] <= target)
        if(nums[0] <= target)
            dp[nums[0]] = true;
        
        // convert states into loops
        for(int i = 1; i < n; i++) {
            temp[0] = true;     // as on any index, if only true when target == nums[i]

            for(int k = 1; k <= target; k++) {
                // copy recurance
                bool noTake = dp[k];
                bool take = false;
                
                if(nums[i] <= k)
                    take = dp[k - nums[i]];

                temp[k] = (take || noTake);
            }

            dp = temp;
        }

        return dp[target];
    }
};