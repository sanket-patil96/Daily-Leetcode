class Solution {
public:
    int minOperations(vector<int>& nums) {
        // optimization using binary search

        int n = 1e5+5;

        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;        // these are not primes

        for(int i = 2; i*i <= n; i++) {
            if(isPrime[i]) {
                for(int j = i*i; j <= n; j += i)
                    isPrime[j] = false;
            }
        }

        // more optimization store the primes in vector, for easy finding next prime using binary search
        vector<int> primes;
        for (int i = 2; i < n; i++) 
            if (isPrime[i]) primes.push_back(i);

        int opr = 0;
        for(int i = 0; i < nums.size(); i++) {
            int x = nums[i];

            if(i & 1) {
                if(!isPrime[nums[i]])  continue;
                if(nums[i] == 2)    opr += 2;
                else                opr++;
            }
            else {
                // gives next equal or greater element
                auto itr = lower_bound(primes.begin(), primes.end(), nums[i]);
                int nextPrime = *itr;
                opr += (nextPrime - nums[i]);
            }
        }

        return opr;
    }
};