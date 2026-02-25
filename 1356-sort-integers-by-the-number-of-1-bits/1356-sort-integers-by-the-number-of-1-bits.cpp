class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        // use method for counting set bits, and sort accordingly

        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }

    static bool cmp (int &a, int &b) {
         // GCC/Clang built-in function (works in older C++ too)
        int setCntA = __builtin_popcount(a); 
        int setCntB = __builtin_popcount(b); 

        if(setCntA == setCntB)
            return a < b;
        
        return setCntA < setCntB;
    }
};