class Solution {
public:
    int rob(vector<int>& nums) {
        // more space optimised: O(1) space
        // as we only required previous 2 results, we don't need to take dp(N) so only save previous 2 results
        int n = nums.size();

        if(n == 1)
            return nums[0];
        
        
        int prev1 = nums[0];
        int prev2 = max(nums[0], nums[1]);           

        for(int i = 2; i < n; i++) {
            int currRobbed = nums[i] + prev1;     // robb current house & add value from non-adjacent houses
            prev1 = prev2;
            prev2 = max(currRobbed, prev2);
        }

        return prev2;       // return max from adjacents, non-adjacents
    }
};