class Solution {
public:
    int longestPalindrome(string s) {
        // get the freqeuncy of each char then remove the char if its already present in map & increment the count
        // coz that can always make a palindrome
        // at last check if map is not empty then return count*2 + 1, 
        // if empty then return count*2, coz we increment count by 1 if there is already present the char

        unordered_map<char, int> m;
        int cnt = 0;

        for(auto c: s)
            m[c]++;

        bool flag = false;

        for(auto c: m) {
            if(c.second % 2 == 0) 
                cnt += c.second;
            
            else {
                cnt += c.second-1;   // don't reset count to 0 coz it should remian in map, so count > 0 & we can add +1 as there is 1 odd number there
                flag = true;
            }
        }

        if(flag)
            return cnt+1;

        return cnt;
    }
};