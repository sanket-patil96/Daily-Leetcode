class Solution {
public:
    
    int swapRequire(vector<int>& v) {
        int swaps = 0;

        // we have to swap 'v' with even indices (0, 2, 4, 6, ...)
        // that's why we use sum(abs(v[i], 2*i)) (2*i)same as i+=2 in loop 
        for(int i = 0; i < v.size(); i++)
            swaps += abs(v[i] - (2*i));
        
        return swaps;
    }

    int minSwaps(vector<int>& nums) {
        // first check if there  are enough number of odds so we can adjust them
        // between the evens. requiredOdds = TotalEvens-1

        int n = nums.size();
        vector<int> evn, odd;

        for(int i = 0; i < n; i++) {
            if(nums[i] % 2 == 0)
                evn.push_back(i);
            else
                odd.push_back(i);
        }

        int c1 = evn.size(), c2 = odd.size();
        if(abs(c1 - c2) > 1)    
            return -1;
        
        // if evens are more then start putting even values at even indices (0, 2, 4, so they all can fit with validation), else odd
        int ans = INT_MAX;

        // the majority element should place on even indices (starting with majority then only we manage to valid array)
        // if both have equal size then we take min swap from both 
        if(c1 >= c2)
            ans = min(ans, swapRequire(evn));
        if(c2 >= c1)
            ans = min(ans, swapRequire(odd));

        return ans;
    }
};