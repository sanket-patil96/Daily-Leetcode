class Solution {
public:
    bool isPowerOfTwo(int n) {
        // Use of Brian Kerningham's Algorithm to check for single occurence of
        // set bit. if the number is 2's power then it must has only 1 set bit
        // brian algo will remove the lsb set bit, so there will be no set bit's
        // remaining after that, exp: 
        // number->binary form
        // 3->0000 0011
        // 4->0000 0100
        // 5->0000 0101
        // 6->0000 0110
        // 7->0000 0111
        // 8->0000 1000
        // The observation we can conclude is that the number which is a power of two has always compulsoryily 1 true bit.
        // Now consider :-
        // bit representation of 7  -> 0111
        // bit representation of 8  -> 1000
        // bitwise AND of 7 and 8 -> 0000
        // we are gonna use this property for for all numbers which are powers of two
        
        if(n <= 0)      return false;
        return n && ((n & (n - 1)) == 0);
    }
};