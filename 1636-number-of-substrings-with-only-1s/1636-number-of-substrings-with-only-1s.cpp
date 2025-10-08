class Solution {
private:
    int MOD = 1000000007;
    
public:
    int numSub(string s) {
        // optimised: T/C: O(N)  S/C: O(N)
        // we use array for next smaller & previous equal OR smaller for every index
        
        // the idea patter similar to question: 907. Sum of Subarray Minimums

        // ex: "0110" for i=1 next smaller = 3 & previous smaller = 0 & no.of subarray = (3-1)*(1-0) = 2
        //  and for i=2 next smaller = 3 & prev Equal = 1, no.of subarray = (3-2)*(2-1) = 1
        // i.e total count = 2+1 = 3  that the correct answer!

        // NOTE: we get previous equal also coz to avoid duplicates '1' subarray that we already counted with previous '1's

        int n = s.size();
        vector<int> nextSm(n, n), prevEqualSmall(n, -1);

        int sm = n;    // for storing index of next smaller
        for(int i = n-1; i >= 0; i--) {
            if(s[i] == '0')  sm = i;
            else  nextSm[i] = sm;
        }

        // previous Smaller OR Equal always be the previous index of i, i.e i-1
        // coz its a binary array [i-1] is either '0' or '1' and both are smaller or equal for '1'
        // '0' doesn't need to be considered!
        for(int i = 0; i < n; i++)
            prevEqualSmall[i] = i-1;
    
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '0')  continue;
            ans += ((nextSm[i] - i) * (i - prevEqualSmall[i])) % MOD;
        }

        return ans % MOD;
    }
};