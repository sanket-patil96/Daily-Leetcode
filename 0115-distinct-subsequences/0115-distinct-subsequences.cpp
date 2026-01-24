class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(); 
        int m = t.size();

        // since using only above row and current row, further optimization can be done
        // steps:
        // create 2 dp array, dp (previous state) & curr (current state)
        
        // T/C: O(N*M)   S/C: O(M)

        // base case: 
        vector<long long> dp(m+1, 0);
        vector<long long> curr(m+1, 0);

        // base case 1:
        // if at any index i if (j == 0) (index shifting) then we return 1
        dp[0] = 1;      // there are no other rows, so don't need loop for i

        // this change needs to be done,  coz in 2D dp, we marked every row = 1 when j = 0,
        // so every new row's first col should be 1
        curr[0] = 1;


        // base case 2:
        // at any index [j >= 1] (j == 0 covered above), if i == 0 (index shifting) then return 0
        // means t is remaining and s exhaust!
        for(int j = 1; j <= m; j++) 
            dp[j] = 0;
        
        // states are i & j, can go up till  <= N & <= M, start from 1 (coz index shifting, row = 0, col = 0 already covered in base case)
        for(int i = 1; i <= n; i++) {

            for(int j = 1; j <= m; j++) {
                // copy the recurrance as it is

                int take = 0;
                if(s[i-1] == t[j-1])   // -1 coz indexes are shifted for dp[i][j]
                    take = dp[j-1];

                int noTake = dp[j];

                curr[j] = (long)take + noTake;
            }

            dp = curr;
        }

        return dp[m];
    }
};