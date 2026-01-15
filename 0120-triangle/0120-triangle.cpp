class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        // space optimization: Tabulation
        // for current index i we can take the *min* choises from previous row's [r-1][i-1]
        // and [r-1][i], these are the only points from where we can reach the current point([r][i])

        
        int n = triangle.size();   // n is total rows & also length of last row (which is max array)

        vector<int> dp(n, INT_MAX);     // we want min path so set all initial points to +infinite
        dp[0] = triangle[0][0];            // set to the first element

        for(int i = 1; i < n; i++) {
            vector<int> temp(n, INT_MAX);
            
            for(int j = 0; j < triangle[i].size(); j++) {

                // if its not having the previous column on above row
                if(j == 0)
                    temp[j] = triangle[i][j] + dp[j];         // add with above column

                // if its above column is not available in previous row of triangle
                else if(j == triangle[i].size()-1) 
                    temp[j] = triangle[i][j] + dp[j-1];

                else 
                    temp[j] = triangle[i][j] + min(dp[j-1], dp[j]);
            }

            dp = temp;
        }

        // now to get the min path traverse the final updated dp array & take minimum
        int minPathSum = INT_MAX;

        for(int i: dp)
            minPathSum = min(minPathSum, i);

        return minPathSum;
    }
};