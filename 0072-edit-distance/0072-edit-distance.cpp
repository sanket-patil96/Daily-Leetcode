class Solution {
public:
    int minDistance(string word1, string word2) {
        // we can try to write recursion on this
        // think everything in term of indexes (i for s1, j for s2)
        // explore all possibilities (3 possibilities on each char)
        // return min from all possibilities (min from insert, delete, update)

        // so we can try all insert, update, delete ways on each unmatching char of word1
        // and return min ans from all 3
        int n = word1.size();
        int m = word2.size();

        // in order to memoize this solution:
        // identify changing parameters (i & j)
        // find their length (i can go till N, j till M)
        // so create 2D DP of [N][M]
        // before returning from anywhere store values in dp[i][j]

        vector<vector<int>> dp(n, vector<int> (m, -1));

        return solve(n-1, m-1, word1, word2, dp);
    }

    int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        // base case, if (j < 0) means, all chars are matched till i from s1
        // now we have to delete extra portion of string s1, no other operations needed, just delete
        // and add the deleted count to operations
        if(j < 0) {
            // i is the no.of extra part from s1, so return that number
            return i+1;  // +1 coz, 0 based indexing, if i = 1 means, 2 chars are extra in s1
            // also work if both strings matches, ex: "a" & "a" then both i & j becomes < 0 which is -1
            // so return -1 + 1 = 0 from here
        }

        // base case 2: if (i < 0) means s1 is insufficient, and need to add j number of characters to s1
        // to make it like s2
        if(i < 0) {
            return j+1;         // +1 coz 0 based indexing, means, if j = 1, s1 needs to add 2 more chars to itself
        }

        if(dp[i][j] != -1)
            return dp[i][j];

        // if current characters from both strings matches, then don't need to do any operation
        if(s1[i] == s2[j])
            return dp[i][j] = solve(i-1, j-1, s1, s2, dp);

        // if no match then we have 3 operations
        
        // in insertion no need to actual insertion, just assume we inserted same char in s1 after index i, like in s2[j]
        // so this means they match, so reduce s2 size and add +1 & call further, don't reduce i as we inserted new element, so current char at [i] remain as it is
        int insertion = 1 + solve(i, j-1, s1, s2, dp);

        // same here no need to actually delete a char from s1, just skip this, and do i--, j remains same & add +1 for deletion operation
        int deletion = 1 + solve(i-1, j, s1, s2, dp);

        // don't actually update, if we update means s[i] == s[j], so just reduce string size i--, j-- & +1 for updation operation
        int updation = 1 + solve(i-1, j-1, s1, s2, dp);

        return dp[i][j] = min({insertion, deletion, updation});
    }
};