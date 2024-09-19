class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) 
            return 0;
        if(n == 1 || n == 2) 
            return 1;
        
        // initializing first 3 numbers:
        int a = 0;
        int b = 1;
        int c = 1;
        int ans = 0;
        
        // start loop from 3 others are handled in initialization
        for(int i = 3; i <= n; i++) {
            ans = a+b+c;
            a = b;
            b = c;
            c = ans;
        }
        
        return ans;
    }
};