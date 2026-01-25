class Solution {
public:
    bool isMatch(string s, string p) {
        // with help of more test cases, i understand that we have to match all characters from 'p' to 's'
        // means (p == s) & if there is '*' in p then it can match to any characters, '?' can only match 1 character
        // this is similar to the previously solved question, EDIT Distance, (with help of insert, replace, delete)
        // here is same, if chars at s[i] != p[j] not matching, and at p[j] = '?' means we can replace ? with s[i], so reduce string sizes i-1, & j-1
        // and if p[j] = '*', means also we can hypothetically match them, and do i-1 (for s only)
        // and now we have 2 options, 
        // 1] keep p[j] at '*' to match further chars
        // 2] reduce j-1, by hoping there are other matching characters in p[0..j] 
        // exp: s = 'bxybmhj' p = 'b*hj', here last 'hj' matches & with '*' we match 'xyb' and first 'b' of s mathces with first 'b' in p, return true

        // so we need to use recursion here for all finding possibilities
        // rules:
        // think everything in term of indexes (i & j here)
        // explore all paths (1.keeping j at '*' after matching with s[i] or 2.reducing j-1 after matching with s[i], or don't even match to s[i] & reduce j-1 but keep i as it is)
        // return true if both strings match end to end

        int n = s.size();
        int m = p.size();

        // use memoization
        // rules: 
        // identify changing states: (i & j here)
        // find their reach, i can go from 0 -> n & j can 0 -> m
        // create dp[n][m]
        // store result to dp[i][j] before returning

        vector<vector<int>> dp(n, vector<int> (m, -1));     // can't use bool, as we have  to store  all false then
        return solve(n-1, m-1, s, p, dp);
    }

    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp) {

        // base case 0: exception case '*' can match to empty string also, exp: ("adceb" & "**a*b") returns true
        if(i < 0 && (j >= 0 && p[j] == '*'))
            return solve(i, j-1, s, p, dp);     // as s becomes empty, so no need to reduce i, & also no need to keep j at '*' so move ahead, to see if p also becomes empty (j < 0)

        // base case 1: if both becomes empty (indexes reaches -1) then only it means s & p fully matched
        if(i < 0 && j < 0)
            return true;
        
        // base case 2: if one of them exhaust means they not fully match!
        if(i < 0 || j < 0)
            return false;
        
        if(dp[i][j] != -1)
            return dp[i][j];

        // if both chars match  OR if p[j] = '?' means, we can replace '?' with s[i], so reduce both strings size by -1
        if(s[i] == p[j] || p[j] == '?') 
            return dp[i][j] = solve(i-1, j-1, s, p, dp);
        
        // else check for if there is '*' at p[j] there are 2 options, only match current char with '*' and move both pointers i-1 & j-1
        // or keep j on '*' for further matching
        else if(p[j] == '*') {
            return dp[i][j] = solve(i-1, j-1, s, p, dp) || 
                              solve(i-1, j, s, p, dp) || 
                              solve(i, j-1, s, p, dp);
        }

        // else, p[j] can't be matched with s[i], return false
        else
            return dp[i][j] = false;
    }
};