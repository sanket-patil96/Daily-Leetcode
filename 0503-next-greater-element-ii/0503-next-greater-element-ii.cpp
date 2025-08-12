class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // we use the monotonic Stack approach as for normal array 
        // and as this is circular array, we have to store the left side values also 
        // coz this can be the greater for last  few elements, 
        // ex: [1,2,3,1,0] in this for last 2 values[1,0] there is [2, 1] are the next greater values
        // so from left side we will only store the elements in increasing order (coz lesser won't useful coz previous are coming early so they can be immediate next greater in circular form for next values)
        // and at last for the elements in stack, you use that leftMax array to find the next greater elements for each
        // and as we have decreasing elements in stack, we don't required to start again from index 0 for leftMax, coz last top element in stack is lesser than the new top, so 
        // we can find further elements from the last index in leftMax array
        
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> s;
        vector<int> leftMax;

        s.push(0);
        leftMax.push_back(nums[0]);

        for(int i = 1; i < n; i++) {
            while(s.size() && nums[s.top()] < nums[i]) {
                ans[s.top()] = nums[i];
                s.pop();
            }

            s.push(i);
            if(leftMax.back() < nums[i])
                leftMax.push_back(nums[i]);
        }

        // now check next circular greater values for the elements in the stack 
        int j = 0;      // to track the left Max values 
        int m = leftMax.size();

        while(s.size()) {
            while(j < m && leftMax[j] <= nums[s.top()])
                j++;

            if(j == m)
                break;
            
            ans[s.top()] = leftMax[j];
            s.pop();
        }

        return ans;
    }
};