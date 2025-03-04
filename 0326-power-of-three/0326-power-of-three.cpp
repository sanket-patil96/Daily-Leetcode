class Solution {
public:
    bool isPowerOfThree(int n) {
        if(!n) return false;        // means n is <= 0
        
        if(n == 1) return true;
        
        return n % 3 == 0 && isPowerOfThree(n/3);
    }
};