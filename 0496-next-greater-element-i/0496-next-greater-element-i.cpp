class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // use a stack to push incoming elements
        // if top element is < current ith element then store the top element as key & value of it as current element in map
        // so as this will store the next greater element for each element
        // then store current element after deleting the top(if it is lesser than current)

        stack<int> s;
        unordered_map<int, int> m;
        vector<int> ans;

        for(auto n: nums2) {
            while(s.size() && s.top() < n) {
                m[s.top()] = n;
                s.pop();
            }

            s.push(n);
        }

        for(auto i: nums1) {
            ans.push_back(m.count(i) ? m[i] : -1);
        }

        return ans;
    }
};