class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        // c is original size of cuts
        int c = cuts.size();

        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        
        // time: O(C^3)    space: O(c*c) + auxilary recursion stack space

        vector<vector<long long>> dp(c+2, vector<long long> (c+2, -1));  // +2 coz added 2 elements in original size 'c'

        return solve(1, c, cuts, dp);   // c is at 2nd last index of new cuts array (so j+1 won't be out of bounds)
    }

    long long solve(int i, int j, vector<int> &cuts, vector<vector<long long>> &dp) {
        if(i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        long long mini = LLONG_MAX;

        // cuts can start from any point
        for(int k = i; k <= j; k++) {
            long long cost = cuts[j+1] - cuts[i-1]
                            + solve(i, k-1, cuts, dp)
                            + solve(k+1, j, cuts, dp);
            mini = min(mini, cost);
        }

        return dp[i][j] = mini;
    }
};