class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int countOnes = 0;    // it will count no.of 1's in string to judge flips
        int countFlips = 0;   // means it will count bits which converted 0->1

        for(int i = 0; i < s.size(); i++)  {
            if(s[i] == '1')
                countOnes++;

            // if 0 occurs after 1 then flip 
            else if(s[i] == '0' && (countOnes > 0))
                countFlips++;   

            // we will change flips, such as we counted for fliping the ones
            if(countOnes < countFlips)
                countFlips = countOnes;
        }   

        return countFlips;
    }
};