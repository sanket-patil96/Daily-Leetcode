class Solution {
public:
    int solve(int i, int sum, vector<int> &nums, int target) {
        if(i == nums.size())
            return sum == target;

        // take it with + sign
        // take it with - sign
        return solve(i+1, sum+nums[i], nums, target) + 
                solve(i+1, sum-nums[i], nums, target);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        // we gave try all ways with first give + sign then - (take it or not take it type)
        int sum = 0;
        return solve(0, sum, nums, target);
    }
};