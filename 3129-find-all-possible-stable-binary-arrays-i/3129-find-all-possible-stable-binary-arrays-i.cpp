class Solution {
private:
    int MOD = 1e9+7;
    int dp[201][201][2][201];

public:

    int solve(int zero, int one, int last, int count, int limit){

        if(zero == 0 && one == 0)
            return 1;

        if(dp[zero][one][last][count] != -1)
            return dp[zero][one][last][count];

        long long ans = 0;

        // place 0
        if(zero > 0){
            if(last == 0){
                if(count < limit)
                    ans += solve(zero-1, one, 0, count+1, limit);
            }
            else{
                ans += solve(zero-1, one, 0, 1, limit);
            }
        }

        // place 1
        if(one > 0){
            if(last == 1){
                if(count < limit)
                    ans += solve(zero, one-1, 1, count+1, limit);
            }
            else{
                ans += solve(zero, one-1, 1, 1, limit);
            }
        }

        return dp[zero][one][last][count] = ans % MOD;
    }

    int numberOfStableArrays(int zero, int one, int limit) {

        memset(dp, -1, sizeof(dp));

        long long ans = 0;

        // start with 0
        if(zero > 0)
            ans += solve(zero-1, one, 0, 1, limit);

        // start with 1
        if(one > 0)
            ans += solve(zero, one-1, 1, 1, limit);

        return ans % MOD;
    }
};