class Solution {
public:
    bool isPalindrome(int st, int e, string s) {
        while(st < e) 
            if(s[st++] != s[e--])
                return false;

        return true;
    }

    int palindromeCount(int st, int e, string s) {
        int cnt = 0;
        while(st >= 0 && e < s.size() && (s[st--] == s[e++]))  {
            cnt++;
        }
        return cnt;
    }

    int countSubstrings(string s) {
        int ans = 0;
        // brute force:
        // for(int i = 0; i < s.size(); i++) {
        //     for(int j = i; j < s.size(); j++) {
        //         if(isPalindrome(i, j, s))
        //             ans++;
        //     }
        // }


        for(int i = 0; i < s.size(); i++) {
            // Count even-length palindromes (centered between i and i+1)
            int even = palindromeCount(i, i+1, s);
            // Count odd-length palindromes (centered at i)
            int odd = palindromeCount(i-1, i+1, s);
            ans += (even + odd)+1;      // +1 for the current character
        }

        return ans;
    }
};