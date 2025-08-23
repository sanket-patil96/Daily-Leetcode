class Solution {
public:
    int reverse(int x) {

        string s = to_string(x);

        std::reverse(s.begin(), s.end());

        long ans = stol(s);

        // handle large values
        if(ans <= -pow(2, 31) || ans >= pow(2, 31))
            return 0;

        // handle negative edge cases
        if(x < 0)
            ans = -ans;

        return ans;
    }
};