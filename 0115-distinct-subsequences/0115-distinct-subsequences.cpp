class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(); 
        int m = t.size();

        // on giving a close observation i can also more space optimise it to single array
        // how? 
        // calculating  for curr[j], if s[j-1] == t[j-1] then we storing dp[j-1]'s value to curr[j]
        // and if no match, then we storing the above col's value, i.e curr[j] = dp[j]
        
        // lets try by modifying same dp (prev array) array for every rows:
        // for current cell [j]
        // take - if match, we update dp[j] to its dp[j-1] value,
        // noTake- we need to get prev dp[j]'s value as it is, but we have modified it in take call
        // so it fails here!

        // solution:
        // in take call we changing current cell [j] with prev value from array
        // in noTake call we don't need any prev value just require above value (current cell)
        // so we can start traversing j from M and go till >= 1
        // that the solutions

        // so we can use same array for both take, noTake work,
        
        // T/C: O(N*M)   S/C: O(M) single array

        // base case: 
        vector<long long> dp(m+1, 0);

        // base case 1:
        // if at any index i if (j == 0) (index shifting) then we return 1
        dp[0] = 1;      // there are no other rows, so don't need loop for i

        // base case 2:
        // at any index [j >= 1] (j == 0 covered above), if i == 0 (index shifting) then return 0
        // means t is remaining and s exhaust!
        for(int j = 1; j <= m; j++) 
            dp[j] = 0;
        
        // states are i & j, can go up till  <= N & <= M, start from 1 (coz index shifting, row = 0, col = 0 already covered in base case)
        for(int i = 1; i <= n; i++) {

            // need to change the order, start from reverse
            for(int j = m; j >= 1; j--) {
                // copy the recurrance as it is

                int take = 0;
                if(s[i-1] == t[j-1])   // -1 coz indexes are shifted for dp[i][j]
                    take = dp[j-1];

                int noTake = dp[j];

                dp[j] = (long)take + noTake;
            }
        }

        return dp[m];
    }
};