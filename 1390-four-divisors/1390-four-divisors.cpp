class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        // try brute force:
        // check all divisors from 1 to ith value
        // if exactly 4 divisors then add sum in totalValue, else ignore

        int totalSum = 0;

        for(int i: nums) {
            int divisors = 0;
            int sum = 0;

            // ith value is *included
            for(int d = 1; d <= i; d++) {
                if(i % d == 0) {
                    sum += d;
                    divisors++;

                    if(divisors > 4)
                        break;
                }
            }

            // cout << i << " d: " << divisors << " S: " << sum << endl;

            if(divisors == 4)
                totalSum += sum;
        }

        return totalSum;
    }
};