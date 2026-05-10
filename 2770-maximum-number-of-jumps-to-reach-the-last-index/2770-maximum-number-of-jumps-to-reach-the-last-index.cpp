class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        // maximum jumps possible are  n, so i guess we just need to find if on next index we can jump or not
        // but from all possible options withing target :(
        // lets try recusion

        int n = nums.size();

        if(n == 1)
            return 0;

        vector<vector<int>> memo(n, vector<int>(n + 1, INT_MIN));

        int res = solve(0, 1, nums, target, memo);

        return res <= 0 ? -1 : res;
    }

    int solve(int i, int j, vector<int> &nums, int target, vector<vector<int>> &memo) {
        if(i == nums.size() -1) 
            return 0;

        if(j == nums.size()) 
            return -1e9;

        if(memo[i][j] != INT_MIN)
            return memo[i][j];

        int take = -1e9, noTake = 0;

        if(-target <= (nums[j]-nums[i]) && (nums[j]-nums[i]) <= target) {
            take = 1 + solve(j, j+1, nums, target, memo);
        }

        noTake = solve(i, j+1, nums, target, memo);

        return memo[i][j] = max(take, noTake);
    }
};