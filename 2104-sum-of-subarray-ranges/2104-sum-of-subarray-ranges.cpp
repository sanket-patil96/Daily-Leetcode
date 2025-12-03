class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        // we just need to find out for how many subarrays element 'a' is smaller & same for largest
        // we get contribution of all elements for being smaller & for being largest
        // then just substract largestSum - smallerSum, this is our final answer

        int n = nums.size();
        
        long long minSum = findMinSubarrays(nums, n);
        long long maxSum = findMaxSubarrays(nums, n);
        
        return maxSum - minSum;
    }

    long long findMinSubarrays(vector<int> &a, int n) {
        vector<int> nextSmaller = findNextSmaller(a, n);
        vector<int> prevSmaller = findPrevSmaller(a, n);           // consider  equal value of previous subarray

        long long total = 0;

        for(int i = 0; i < n; i++) {
            // get the contribution of a[i] for every subarray where it is minimum
            int rightSubarr = nextSmaller[i] - i;
            int leftSubarr = i - prevSmaller[i];
            total += (long)a[i] * (rightSubarr) * (leftSubarr);
        }

        return total;
    }

    long long findMaxSubarrays(vector<int> &a, int n) {
        vector<int> nextLarger = findNextLarger(a, n);        
        vector<int> prevLarger = findPrevLarger(a, n);

        long long total = 0;

        for(int i = 0; i < n; i++) {
            // get the contribution of a[i] for every subarray where it is maximum
            int rightSubarr = nextLarger[i] - i;
            int leftSubarr = i - prevLarger[i];
            total += (long)a[i] * rightSubarr * leftSubarr;
        }

        return total;
    }

    vector<int> findNextSmaller(vector<int> &a, int n) {
        vector<int> ans(n, n);
        stack<int> s;
        s.push(0);            // push first element index

        for(int i = 1; i < n; i++) {
            while(s.size() && a[s.top()] > a[i]) {
                ans[s.top()] = i;
                s.pop();
            }

            s.push(i);
        }

        return ans;
    }

    vector<int> findNextLarger(vector<int> &a, int n) {
        vector<int> ans(n, n);
        stack<int> s;
        s.push(0);            // push first element index

        for(int i = 1; i < n; i++) {
            while(s.size() && a[s.top()] < a[i]) {
                ans[s.top()] = i;
                s.pop();
            }

            s.push(i);
        }

        return ans;
    }

    vector<int> findPrevSmaller(vector<int> &a, int n) {
        vector<int> ans(n, -1);
        stack<int> s;
        s.push(0);            // push first element index

        for(int i = 1; i < n; i++) {
            while(s.size() && a[s.top()] > a[i]) {
                s.pop();
            }

            ans[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        return ans;
    }

    vector<int> findPrevLarger(vector<int> &a, int n) {
        vector<int> ans(n, -1);
        stack<int> s;
        s.push(0);            // push first element index

        for(int i = 1; i < n; i++) {
            while(s.size() && a[s.top()] < a[i]) {
                s.pop();
            }

            ans[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        return ans;
    }
};