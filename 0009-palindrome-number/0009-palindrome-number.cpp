class Solution {
public:
    bool isPalindrome(int x) {
        int rem = 0;
        long val = 0;
        int temp = x;

        while(temp > 0) {
            rem = temp%10;
            val = (val*10) + rem;
            temp /= 10;
        }
        if (val == x)
        {
            return true;
        }
        return false;   
    }
};