class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // space optimization is possible as we are only using previous row

        int n = text1.size();
        int m = text2.size();

        vector<int> dp(m+1, 0);
        vector<int> temp(m+1, 0);

        for(int j = 0; j <= m; j++)  dp[j] = 0;
        // no need to do same for i as only 1 row is there

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                // copy recurrance

                if(text1[i-1] == text2[j-1])
                    temp[j] = 1 + dp[j-1];

                else temp[j] = max(temp[j-1], dp[j]);   // change: take max from prev row[j] & current row[j-1]
            }

            dp = temp;
        }

        return dp[m];
    }

};