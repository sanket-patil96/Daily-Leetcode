class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // similar to Longest Common Substring (https://www.notion.so/Longest-Common-Substring-2f03af0b2b3680c4816cc64be15dab2c?source=copy_link)

        // space optimization
        int n = nums1.size();
        int m = nums2.size();

        vector<int> dp(m+1, 0);
        vector<int> curr(m+1, 0);
        
        // base case
        for(int j = 0; j <= m; j++)
            dp[j] = 0;

        int ans = 0;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(nums1[i-1] == nums2[j-1]) {   // -1 coz used index shifting
                    curr[j] = 1 + dp[j-1];
                    ans = max(ans, curr[j]);
                }

                // as we only can get consecutive, so can't getting max from left & above column like we do in LCS (subsequence problem)
                else curr[j] = 0;
            }
            
            dp = curr;
        }
        

        return ans;
    }
};