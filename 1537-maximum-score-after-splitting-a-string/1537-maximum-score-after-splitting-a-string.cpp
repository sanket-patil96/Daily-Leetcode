class Solution {
public:
    int maxScore(string s) {
        // first count no.of 1's & 0's
        // then while traversing string split string & add OR remove the gone 0s or 1s from both parts

        int zeros = 0, ones = 0;

        for(char ch: s) {
            if(ch == '0')
                zeros++;
            else
                ones++;
        }

        // split string
        int ans = 0;
        int cntZeros = 0;

        // -1 so there will not be empty substring at last
        for(int i = 0; i < s.size()-1; i++) {
            // count left part only & we automatically get right part
            if(s[i] == '0')
                cntZeros++;

            int leftSide = cntZeros;
            
            // current substr_len - zeros = ones in left, so 1s on right = total ones-left ones
            int rightSide = ones-abs(i+1-cntZeros);      
            ans = max(ans, leftSide+rightSide);
        }

        return ans;
    }
};