class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // we can space optimize it as we using only prev & curr rows here

        vector<int> dp(m+1, 0);    // prev row 
        vector<int> curr(m+1, 0);  // current row

        // base case 1: (j = 0) return i, for any index i, (after index shifting j < 0 becomes j = 0)
        // as there are only 2 1D rows
        dp[0] = 0;       // j = 0 & i = 0  (first row)
        curr[0] = 1;     // j = 0, i = 1  (second row), changing for any row, so, need to be continiously updated in every row

        // base case 2: (i = 0) return j for any index j;
        for(int j = 0; j <= m; j++)
            dp[j] = j;      // no j+1 as did in memo, coz here actual indexing starts from 1

        // convert states, i, j to loops,
        // i can go from 1 to <= n, j from 1 to <= m (start from 1 coz index shifting & i = j = 0,  covered in base case)
        for(int i = 1; i <= n; i++) {
            curr[0] = i;     // base case: (j = 0) return i, for every row i

            for(int j = 1; j <= m; j++) {
                // copy the recurrance

                if(word1[i-1] == word2[j-1])      // -1 coz index shifting
                    curr[j] = dp[j-1];

                else {
                    int insertion = 1 + curr[j-1];  // using current row's left column here

                    int deletion = 1 + dp[j];

                    int updation = 1 + dp[j-1];

                    curr[j] = min({insertion, deletion, updation});
                }
            }

            dp = curr;
        }

        return dp[m];
    }
};