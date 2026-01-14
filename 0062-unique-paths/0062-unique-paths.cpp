class Solution {
public:

    int recur(int r, int c, int m, int n, vector<vector<int>> &memo) {
        if(r >= m || c >= n)
            return 0;

        if(memo[r][c] != -1)
            return memo[r][c];

        if(r == m-1 && c == n-1) 
            return 1; 

        return memo[r][c] = recur(r+1, c, m, n, memo) + recur(r, c+1, m, n, memo);
    }

    int uniquePaths(int m, int n) {
        // we can count paths that can occur from both down and right 
        // this will be basic recursion

        // now to optimise it we can use memoization with 2 parameters, {r, c}
        vector<vector<int>> memo(m, vector<int> (n, -1));
        return recur(0, 0, m, n, memo);
    }
};