class Solution {
public:
    bool isPowerOfTwo(int n) {
        // lic:
        if(!n) return false;    // base condition when n <= 0
        if(n == 1) return true;
        return n % 2 == 0 and isPowerOfTwo(n / 2);
    }
};