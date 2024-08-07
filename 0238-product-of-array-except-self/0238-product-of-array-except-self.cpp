class Solution {
public:

    vector<int> productExceptSelf(vector<int>& nums) {
        // Third method using Single array 
        // time: O(N)  space: O(1)
        int n = nums.size();
        vector<int> ans(n);

        
        // work like prefix product array
        int curr = 1;
        for(int i = 0; i < n; i++)
        {
            ans[i] = curr;
            curr *= nums[i];        // update prefix prod for next elem
        }

        // work like suffix product array
        curr = 1;
        for(int i = n-1; i >= 0; i--)
        {
            ans[i] *= curr;         // multiply by right product for ans[i] which is product from left
            curr *= nums[i];        // calculate suffix product from right
        }

        return ans;
    }
};