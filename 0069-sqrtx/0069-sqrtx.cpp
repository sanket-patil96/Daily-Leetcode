class Solution {
public:
    // using binary search
    int mySqrt(int x) {
        int l = 0, r = x;
        while(l < r){
            long long mid = l + ((long long)r - l + 1) / 2;
            if(mid * mid <= (long long)x)
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
};