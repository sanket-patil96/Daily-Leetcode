class Solution {
public:
    int binaryGap(int n) {
        // just count the how many bits after anohter 1 occurs in bits
        int diff = 0;
        int maxDiff = 0;
        bool found1 = false;
        while(n) {
            if(n & 1) {
                found1 = true;
                maxDiff = max(maxDiff, diff);
                diff = 1;       // reseat diffenrence from current bit, as from here we have to find new pair of 1's
            }
            // only increment the difference when earlier we have found a '1', coz we have to find gap beween 1's
            else if(found1) 
                diff++;


            n >>= 1;
        }

        return maxDiff;
    }
};