class Solution {
private:
    int MOD = 1000000007;
public:

    int solve(int i, vector<long> &memo, string &s) {
        if(i >= s.size() || s[i] == '0')
            return 0;

        if(memo[i] != -1)
            return memo[i];

        // get the count from further substring & add 1 for current '1'
        return memo[i] = ((solve(i+1, memo, s) % MOD) + 1) % MOD;
    }

    int numSub(string s) {
        // brute force: 
        // we go with checking on each index if its value is '0' then skip it
        // if '1' then we go further for checking it's further substrings, increase count with each length increment

        // optimization:
        // use memoization for avoiding TLE!
        long long ans = 0;
        int n = s.size();

        vector<long> memo(n, -1);
        
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') continue;

            // add the 1 for the current 1
            ans += solve(i, memo, s) % MOD;
        }

        return ans % MOD;
    }
};