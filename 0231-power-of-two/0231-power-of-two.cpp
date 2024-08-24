class Solution {
public:
    bool isPowerOfTwo(int n) {
        // Use of Brian Kerningham's Algorithm to check for single occurence of set bit.
        // if the number is 2's power then it must has only 1 set bit
        // brian algo will remove the lsb set bit, so there will be no set bit's remaining after that
        return n && ((n & (n-1)) == 0);
    }
};