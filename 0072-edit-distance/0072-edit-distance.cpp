class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // lets convert this to tabulation now, steps:
        // define base case: (i < 0 | j < 0 going negative so need index shifting)
        // convert states to loops
        // copy recurrance:

        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

        // base case 1: (j = 0) return i+1, for any index i, (after index shifting j < 0 becomes j = 0)
        for(int i = 0; i <= n; i++)
            dp[i][0] = i;       // no i+1 as did in memo, coz here actual indexing starts from 1
        
        // base case 2: (i = 0) return j+1 for any index j;
        for(int j = 0; j <= m; j++)
            dp[0][j] = j;      // no j+1 as did in memo, coz here actual indexing starts from 1

        // convert states, i, j to loops,
        // i can go from 1 to <= n, j from 1 to <= m (start from 1 coz index shifting & i = j = 0,  covered in base case)
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                // copy the recurrance

                if(word1[i-1] == word2[j-1])      // -1 coz index shifting
                    dp[i][j] = dp[i-1][j-1];

                else {
                    int insertion = 1 + dp[i][j-1];

                    int deletion = 1 + dp[i-1][j];

                    int updation = 1 + dp[i-1][j-1];

                    dp[i][j] = min({insertion, deletion, updation});
                }
            }
        }

        return dp[n][m];
    }
};