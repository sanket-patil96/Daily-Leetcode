class Solution {
public:
    int minOperations(vector<int>& nums) {
        int opr = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            bool flag = isPrime(nums[i]);
            if((i % 2 == 0 && !flag)) 
                opr += nextPrime(nums[i]) - nums[i];
            
            else if(i % 2 && flag) 
                opr += nextNonPrime(nums[i]) - nums[i];
        }

        return opr;
    }

    bool isPrime(int num) {
        if(num <= 1)
            return false;
        
        if(num == 2 || num == 3)
            return true;

        if(num % 2 == 0 || num % 3 == 0)
            return false;

        for(int i = 5; i*i <= num; i += 6) {
            if(num % i == 0 || num % (i+2) == 0)
                return false;
        }

        return true;
    }

    int nextPrime(int n) {
        n++;
        while(true) {
            if(isPrime(n))
                return n;
            n++;
        }

        return n;
    }
    
    int nextNonPrime(int n) {
        n++;
        while(true) {
            if(!isPrime(n))
                return n;
            n++;
        }

        return n;
    }
};