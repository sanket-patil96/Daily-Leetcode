class Solution {
public:
    int findComplement(int n) {
        // method 2
        unsigned mask = ~0;
        while (n & mask) mask <<= 1;
        return ~mask & ~n;
    }
};