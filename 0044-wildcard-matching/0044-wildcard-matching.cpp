class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        // convert to dp
        // rules:
        // define base case (i < 0 | j < 0, so need index shifting)
        // convert states to loops (i, j)
        // copy the recurrance

        // create dp of size [n+1][m+1] as used index shifting
        vector<vector<bool>> dp(n+1, vector<bool> (m+1, false));     


        // base case 1: if i == 0 && j == 0 then only return true; (i,j == 0 coz shifting of indexes for dp)
        dp[0][0] = true;

        // base case 2: if  i == 0 | j == 0, means only 1 of them ends, then return false
        // start loop from 1 coz, 0 handled in case 1 above
        for(int i = 1; i <= n; i++) dp[i][0] = false;
        for(int j = 1; j <= m; j++) dp[0][j] = false;

        // write after case 1 & 2 only, coz dp[0][j-1] depends on first column dp[0][0] where we set to true;
        
        // base case 0: i == 0 && (j >= 1 && p[j] == '*')       //indexes considered according to shifting
        // means for i == 0 if j > 1 & p[j] = '*' then take ans from dp[i][j-1]
        for(int j = 1; j <= m; j++) {
            if(p[j-1] == '*')     // j-1 coz ind shifting on dp (added +1), so for string its j-1
                dp[0][j] = dp[0][j-1];
        }

        // states -> loops
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                // copy recurrance

                if(s[i-1] == p[j-1] || p[j-1] == '?') 
                    dp[i][j] = dp[i-1][j-1];
                
                else if(p[j-1] == '*') {
                    dp[i][j] = dp[i-1][j-1] || 
                                dp[i-1][j]   || 
                                dp[i][j-1];
                }

                // else, p[j] can't be matched with s[i], return false
                else
                    dp[i][j] = false;
            }
        }

        return dp[n][m];
    }

};