class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        // things to keep in mind:
        // have to manage the limits  of each factory
        // each factory can repair limit times of robots
        // try take / noTake approach on factories for each robots, and minimize the global optimal
        // f(Robo-i, Fact-j): either robo can repair at current  factory, or in other factory
        // for every factory try to get min cost by repairing its limit no.of further robots
        // to do this first sort both robots & factories by their positions
        
        // To optimize lets catch results using DP
        
        int n = robot.size();
        int m = factory.size();

        vector<vector<long long>> dp(n, vector<long long>(m, -1));

        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        return solve(0, 0, robot, factory, dp);
    }

    long long solve(int i, int j, vector<int> &robot, vector<vector<int>> &fact, vector<vector<long long>> &dp) {
        if(i == robot.size())
            return 0;               // all robots get fixed!
        if(j == fact.size())
            return 1e18;         // no factories left

        if(dp[i][j] != -1)
            return dp[i][j];

        // skip fixing robot at current factory
        long long ans = solve(i, j+1, robot, fact, dp);  

        long long cost = 0;
        int pos = fact[j][0];
        int limit = fact[j][1];

        // try to repair next limit no.of robots with current factory
        for(int k = 0; k < limit && i+k < robot.size(); k++) {
            cost += abs(robot[i+k] - pos);
            ans = min(ans, cost + solve(i+k+1, j+1, robot, fact, dp));  // jump to new robot with new factory
        }

        return dp[i][j] = ans;
    }
};