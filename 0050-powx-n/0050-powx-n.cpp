class Solution {
public:
    double myPow(double x, int n) {
        // when there is even power we can do (x*x)^n/2
        // when power is odd we do ans * x ^ n-1
        // we have to handle overflow and -ve n values edge cases

        double ans = 1.0;
        long nn = n;

        // if power is negative
        if(nn<0)    nn = -1 * nn;

        while(nn > 0) {
            if(nn % 2 == 1) {
                ans *= x;
                nn = nn-1;
            }
            else {          // for even power
                x = x*x;
                nn = nn / 2;
            }
        }

        // if OG power is negative, then actual answer: 1 / x^n, so we already calculated x^n just divide by 1 now
        if(n < 0)
            ans = (double) (1.0) / (double) (ans);

        return ans;
    }
};