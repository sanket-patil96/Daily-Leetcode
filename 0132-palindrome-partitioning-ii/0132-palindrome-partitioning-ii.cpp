class Solution {
public:
    int minCut(string s) {
        int n = s.size();

        // memo: 
        // changing states: i
        // range 0-N, create dp[N] = {-1}
        // save before return

        vector<int> dp(n, -1);
        
        return solve(0, s, dp) - 1;         // -1 coz it does a extra partition at end "abc" it does extra partition after c, like: a|b|c| , the last is not needed
    }

    long solve(int i, string &s, vector<int> &dp) {
        if(i == s.size())
            return 0;       // single char is always palindrome, so no need for partitions

        if(dp[i] != -1)
            return dp[i];

        long mini = INT_MAX;

        for(int j = i; j < s.size(); j++) {
            // we can only make partition if temp is palindrome
            if(palindrome(i, j, s)) {
                long cuts = 1 + solve(j+1, s, dp);
                mini = min(mini, cuts);
            }
        }

        return dp[i] = mini;
    }

    bool palindrome(int i, int j, string &s) {
        while(i < j) {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }

        return true;
    }
};