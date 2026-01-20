class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        // For each nums[i]:
        // Try x = 0, 1, 2, 3, ...
        // Check:  x | (x + 1) == nums[i]
        // The first x that matches is the minimum → store it
        // If no x works → store -1
        
        int n = nums.size();
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            int p = nums[i];
            int found = -1;

            if (p == 2) { // impossible case, x | (x+1) is always odd, 2 is even
                ans[i] = -1;
                continue;
            }

            for (int x = 0; x < p; x++) {
                if ((x | (x + 1)) == p) {
                    found = x; // first match = minimum
                    break;
                }
            }

            ans[i] = found;
        }

        return ans;
    }
};