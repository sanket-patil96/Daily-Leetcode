class Solution {
private:
    int MOD = 1000000007;
    
public:
    int numSub(string s) {
        // most optimised: T/C: O(N)  S/C: O(1)
        // count the countinious 1's  & add the counter each time to answer 
        // ex: '111', cnt = 0, ans = 0, on i=0 cnt=1 ans(0) + cnt(1) = 1
        // on i=1 cnt=2  ans(1) + cnt(2) = 3
        // on i=2 cnt = 3, ans(3) + cnt(3) = 6
        // reseat cnt if we encounter a '0'

        int n = s.size();
        long long ans = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            cnt++;
            if(s[i] == '0')  cnt = 0;
            ans += cnt % MOD;
        }

        return ans % MOD;
    }
};