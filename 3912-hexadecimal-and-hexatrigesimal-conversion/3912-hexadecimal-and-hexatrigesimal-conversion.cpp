class Solution {
public:

    string to_base(int n, int base) {
        string s = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string ans = "";

        while(n) {
            ans = s[n%base] + ans;
            n /= base;
        }

        return ans;
    }

    string concatHex36(int n) {
        int sqr = n*n;
        int cube = n*n*n;

        string s1 = to_base(sqr, 16);
        string s2 = to_base(cube, 36);

        return s1+s2;
    }
};