class Solution {
public:

    long long solve(int ind, vector<long long> &dp, vector<vector<int>>& questions) {
        if(ind >= questions.size())
            return 0;       // no more indices left to collect points

        // if from current index there's already max pts we know from now then add that points to the current point
        if(dp[ind] != -1)
            return dp[ind];

        // take it & skip next brainPower indices
        long long take = questions[ind][0] + solve(ind+questions[ind][1]+1, dp, questions);

        // skip it & try taking others
        long long noTake = solve(ind+1, dp, questions);


        return dp[ind] = max(take, noTake);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        // can it be solved using recursion (take it OR don't logic)? 
        // Now we have to use dynamic programming to optimmise it

        // we will use dp array that will store the most maximizing points from current index
        vector<long long> dp(questions.size(), -1);

        return solve(0, dp, questions);    // 0, 0 is starting index of the array & Points
    }
};