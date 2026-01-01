class Solution {
public:

    int climbStairs(int n) {
        // space optimised: O(1)

        // base case
        if(n == 0 || n == 1)
            return n;

        
        int prev1 = 1, prev2 = 1;       // there's only 1 way to reach 1, and for calculating 2nd stair we require previous 2 states

        for(int i = 2; i <= n; i++) {
            int temp = prev1 + prev2;
            prev1 = prev2;
            prev2 = temp;
        }
        
        return prev2;
    }
};