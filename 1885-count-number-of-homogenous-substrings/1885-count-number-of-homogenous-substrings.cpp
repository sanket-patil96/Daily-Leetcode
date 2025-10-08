class Solution {
public:
    int countHomogenous(string s) {
        // similar question https://www.geeksforgeeks.org/problems/count-number-of-substrings4528/1 here just k = 1
        // time: O(n) space: O(1)
        // we just need to count each substring, and if its part of homogenious then everytime add its current homogenious length

        int MOD = 1e9+7;
        int n = s.size();

        // initially add for index 0
        int cnt = 1;
        long long ans = 1;

        for(int i = 1; i < n; i++) {
            if(s[i] == s[i-1])
                cnt++;              // its the part of continuous substring

            else 
                cnt = 1;        // start of new substring

            ans += cnt % MOD;
        }

        return ans % MOD;
    }
};