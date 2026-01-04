class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        // try brute force:
        // check all divisors from 1 to ith value
        // if exactly 4 divisors then add sum in totalValue, else ignore

        // in the very first example, for 21,
        // 21%3==0 so 3 will be added,
        // and at that point, you can also store 7 because 21/3==7,
        // by this approach you need to only search till sqrt(x)

        int totalSum = 0;

        for(int i: nums) {
            int divisors = 0;      
            int sum = 0;           

            // only need to loop till square root of i
            for(int d = 1; d <= sqrt(i); d++) {
                if(i % d == 0) {
                    sum += d;
                    divisors++;

                    if(i/d != d) {
                        sum += i/d;
                        divisors++;
                    }

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