class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;

        for(int i = left; i <= right; i++) {
            if(isPrimeBits(i))
                ans++;
        }

        return ans;
    }

    bool isPrimeBits(int n) {
        int setBits =  0;

        while(n) {
            setBits += n & 1;
            n >>= 1;
        }

        if(setBits < 2)
            return false;

        // max set bits can be 19, so prime till 19 are: [2,3,5,7,11,13,17, 19]

        // unordered_set<int> s = {2, 3, 5, 7, 11, 13, 17, 19};
        // if(s.find(setBits) != s.end())
        //     return true;

        // Or we can check for prime
        for(int j = 2; j*j <= setBits; j++) {
            if(setBits % j == 0)
                return false;
        }

        return true;
    }
};