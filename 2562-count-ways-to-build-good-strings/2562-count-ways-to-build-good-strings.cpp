class Solution {
private:
    int mod = 1000000007;
public:

    int solve(int n, int low, int high, int zero, int one, vector<int> &memo) {
        if(n > high)
            return 0;

        if(memo[n] != -1) 
            return memo[n];
        
        
        // take '0' 'zero' times
        // take '1' 'one' times 
        // we don't need to actually append to string we just want the lenght of string

        int ans = (solve(n+zero, low, high, zero, one, memo) % mod +
                  solve(n+one, low, high, zero, one, memo) % mod) % mod;


        if(n >= low && n <= high) 
            ans++;

        return memo[n] = ans % mod;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        // its simply version of 'take it Or don't take it' type problems,
        // however it will run in given constrains?, lets try.
        // its giving MLE!!!
        // so add memoization to reduce overlaping reconstruction

        vector<int> memo(high+1, -1);

        return solve(0, low, high, zero, one, memo);
    }
};