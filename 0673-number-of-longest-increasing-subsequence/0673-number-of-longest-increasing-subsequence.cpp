class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        // same as LIS, here, just slight change while updating the dp[i]
        // we need to count how many subsequences ends at [i]
        // and at last traverse dp & if dp[i] == maxLen, then do ans += cnt[i]
        // if(dp[j] + 1 > dp[i])
        //      count[i] = 1          // new max length end at ar[i], so reset cnt to 1, as this is the first subsequence with that higher than previous length
        // if(dp[j] + 1 == dp[i])
        //      count[i]++          // same length again found do ++

        int n = nums.size();
        vector<int> dp(n, 1), cnt(n, 1);
        int maxi = 0;

        for(int i = 0; i < n; i++) {

            for(int prev = 0; prev < i; prev++) {
                if(nums[prev] < nums[i] && dp[i] < 1 + dp[prev]) {
                    dp[i] = 1 + dp[prev];
                    cnt[i] = cnt[prev];             // current is the first sequence with longest length that ends at i, so its count will be same as no.of ways ends at cnt[prev]
                }

                else if(nums[prev] < nums[i] && dp[i] == 1 + dp[prev]) {
                    cnt[i] += cnt[prev];            // found another subsequence that ends at i, so its count increamented by the count of the subsequece, that connects with i
                }
            }

            if(maxi < dp[i])
                maxi = dp[i];
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(dp[i] == maxi)
                ans += cnt[i];
        }

        return ans;
    }
};