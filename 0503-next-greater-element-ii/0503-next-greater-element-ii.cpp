class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // approach 2:
        // after first loop there might be some values for which i don't find next greater,
        // but for them that not the end as array is circular, i again traverse the loop from start in same way
        // but this time just need to find the greater vales, don't need to push others in stack
        
        int n = nums.size();
        stack<int> s;
        s.push(0);
        vector<int> ans(n, -1);
        
        for(int i = 1; i < n; i++) {
            while(s.size() && nums[s.top()] < nums[i]) {
                ans[s.top()] = nums[i];        
                s.pop();
            }

            s.push(i);
        }

        // as array is circular, so to find circular next greater for remaining elements in stack (exp: last element of array will always be in stack after first iteration)
        // but this time just find the greater value for stack elements, don't push any other element
        for(int i = 0; i < n; i++) {
            while(s.size() && nums[s.top()] < nums[i]) {
                ans[s.top()] = nums[i];        
                s.pop();
            }
        }

        return ans;
    }
};