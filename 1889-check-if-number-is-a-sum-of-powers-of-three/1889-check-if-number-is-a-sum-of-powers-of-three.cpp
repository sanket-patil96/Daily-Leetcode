class Solution {
public:
    bool checkPowersOfThree(int n) {
        // Intuition
        // This problem requires us to determine if a number can be expressed as a sum of distinct powers of three. For example, powers of three are: 3^0 = 1, 3^1 = 3, 3^2 = 9, 3^3 = 27, and so on. We need to find if some combination of these powers (without repeating any) can sum up to the given number.

        // Approach
        // The solution uses a greedy approach that works from the largest possible power of three down to the smallest:

        // Start from 3^14 (which is approximately 4.8 million, sufficient for the constraint n ≤ 10^7)

        // For each power of three, check:

        // If n is greater than the current power, subtract it from n and continue
        // If n equals the current power exactly, return true immediately
        // If n is less than the current power, skip to the next smaller power
        // If we've gone through all powers and n isn't zero or couldn't be matched exactly to a power, return false

        // This approach works because the powers of three have the property that any number that can be represented as a sum of distinct powers of three will be detected by this greedy algorithm.

        // Complexity
        // Time complexity:O(logn) - we perform at most 15 iterations regardless of input size
        // Space complexity:O(1)

        for(int i = 14; i >= 0; i--) {
            int power = pow(3, i);
            if(n > power) 
                n -= power;

            else if(n == power)
                return true;
        }

        return false;
    }
};