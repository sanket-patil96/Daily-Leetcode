class Solution {
public:
    string longestPalindrome(string s) {
        // start from middle part, if they match, expand from the middle part from where they start matching, for right & left
        // consider for both even & odd substrings

        int n = s.size();

        auto expand_from_center = [&](int left, int right) {
            while(left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }

            // taking -1 coz both left & right are now out of the valid palindrome range, that's why loop stops
            // so take their valid previous posions(that is left+1 & right-1)
            return s.substr(left+1, right-left-1);
        };

        string maxStr = s.substr(0, 1);
        for(int i = 0; i < n-1; i++) {
            string odd = expand_from_center(i, i);
            string even = expand_from_center(i, i+1);

            if(odd.length() > maxStr.length())
                maxStr = odd;

            if(even.length() > maxStr.length())
                maxStr = even;
        }

        return maxStr;
    }
};