class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        // space optimization: Tabulation
        // for current index i we can take the *min* choises from previous row's [r-1][i-1]
        // and [r-1][i], these are the only points from where we can reach the current point([r][i])

        // some change:
        // tabulation is always opposite from recursion, 
        // as in recursion we did 0 -> n-1, so here we do n-1 -> 0

        int n = triangle.size();   // n is total rows & also length of last row (which is max array)

        vector<int> dp = triangle[n-1];    // set to the last row
        
        for(int i = n-2; i >= 0; i--) {
            vector<int> temp(n, INT_MAX);

            // take the min from going straight down OR doing diagonally FROM next row
            for(int j = 0; j < triangle[i].size(); j++)
                temp[j] = triangle[i][j] + min(dp[j+1], dp[j]);
            
            dp = temp;
        }


        return dp[0];
    }
};