class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        // the simulation is simply adding nums 2 times in answer array
        int n = nums.size();
        vector<int> ans(2*n);

        for(int i = 0; i < n; i++) {
            ans[i] = nums[i];
            ans[i+n] = nums[i];
        }

        return ans;
    }
};