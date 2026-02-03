class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        // c is original size of cuts
        int c = cuts.size();

        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        // now convert to tabulation:  Time: O(c^3)  space: O(c^2)
        // define base case
        // convert states into loops
        // copy recurrance
        // return the state of initial recursion call

        vector<vector<long long>> dp(c+2, vector<long long> (c+2, 0)); 

        // base case: i > j return 0
        for(int i = 0; i < c+2; i++) 
            for(int j = 0; j < c+2; j++) 
                if(i > j) dp[i][j] = 0;

        // states -> loops
        for(int i = c; i >= 1; i--) {               // start from opposite of top down approach
            for(int j = 1; j <= c; j++) {           // opposite of topdown approach
                // copy recurrance:

                if(i > j)       continue;           // base case handled it

                long long mini = LLONG_MAX;

                for(int k = i; k <= j; k++) {
                    long long cost = cuts[j+1] - cuts[i-1]
                                    + dp[i][k-1]
                                    + dp[k+1][j];
                    mini = min(mini, cost);
                }

                dp[i][j] = mini;
            }
        }

        return dp[1][c];
    }

};