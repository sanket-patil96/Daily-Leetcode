class Solution {
public:

    static bool cmp(string &s1, string &s2) {
        return s1.size() < s2.size();
    }

    int longestStrChain(vector<string>& words) {
        // similar to LIS:

        int n = words.size();

        // sort it as this is subset, problem, & our solution is from subsequence
        // sorting ensures words[i].size == words[j].size + 1, in increasing manner
        sort(words.begin(), words.end(), cmp);

        vector<int> dp(n, 1);     // initially set to 1, as single length subsets is the number itself

        int maxLen = 0; 

        for(int i = 0; i < n; i++) {
            for(int j = i-1; j >= 0; j--) {
                if(isValid(words[i], words[j]) && dp[i] < 1 + dp[j]) {
                    dp[i] = 1 + dp[j];
                }
            }

            if(maxLen < dp[i])
                maxLen = dp[i];     
        }
        
        return maxLen;
    }

    bool isValid(string &s1, string &s2) {
        if(s1.size() != s2.size()+1)        // s1 must be greater than 1 from s2
            return false;

        int i = 0, j = 0;
        int n = s1.size(), m = s2.size();

        while(i < n && j < m) {
            if(s1[i] != s2[j])
                i++;
            else
                i++, j++;
        }

        if(i == n && j == m)
            return true;
        
        if(j == m && i == n-1)
            return true;

        return false;
    }
};