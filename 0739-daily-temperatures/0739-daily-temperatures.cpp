class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // idea is based on next greater element I: https://leetcode.com/problems/next-greater-element-i/
        // see in note tab

        // we use index in stack and check if greater value comes than stack top, then in answer vector on index of stack top
        // store the value of the difference
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> s;

        for(int i = 0; i < n; i++) {
            while(s.size() && temperatures[s.top()] < temperatures[i]) {
                ans[s.top()] = i - s.top();
                s.pop();
            }

            s.push(i);
        }
        
        return ans; 
    }
};