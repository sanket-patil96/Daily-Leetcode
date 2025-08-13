class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {

        // Optimised: advanced version of 907. Sum of Subarray Minimums
        // Sum of sub array max - sum of subarray min = Answer

        long long minSum = sumSubarrayMins(nums);
        long long maxSum = sumSubarrayMax(nums);

        return maxSum-minSum;
    }

    long long sumSubarrayMins(vector<int>& arr) {
        // we calculate for how many subarrays arr[i] can be the minimum and
        // multiply total subarrays into arr[i] so we can get the addition of
        // minimums of that windows we require couple of things, 1.
        // NextSmaller, 2. PrevSmallerEqual

        int n = arr.size();
        int MOD = (int)(1e9 + 7);
        vector<int> nextSm = nextSmaller(arr, n);
        vector<int> prevSm = prevSmallerEqual(arr, n);

        long long total = 0;

        for (int i = 0; i < n; i++) {
            int rightSub = nextSm[i] - i;
            int leftSub = i - prevSm[i];

            total += (rightSub * leftSub * (long)arr[i]);
        }

        return total;
    }

    vector<int> nextSmaller(vector<int>& arr, int n) {
        stack<int> s;
        vector<int> ans(n, n);

        for (int i = 0; i < n; i++) {
            while (s.size() && arr[s.top()] > arr[i]) {
                ans[s.top()] = i;
                s.pop();
            }

            s.push(i);
        }

        return ans;
    }

    vector<int> prevSmallerEqual(vector<int>& arr, int n) {
        stack<int> s;
        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {
            while (s.size() && arr[s.top()] > arr[i]) {
                s.pop();
            }

            ans[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        return ans;
    }

    long long sumSubarrayMax(vector<int>& arr) {
        // Similar logic as sumSubarrayMins but for maximums.
        // For each arr[i], find how many subarrays it can be the maximum in,
        // multiply that count by arr[i], and sum it up.

        int n = arr.size();
        int MOD = (int)(1e9 + 7);

        vector<int> nextGr = nextGreater(arr, n);
        vector<int> prevGr = prevGreaterEqual(arr, n);

        long long total = 0;

        for (int i = 0; i < n; i++) {
            long long rightSub = nextGr[i] - i; // how many choices to the right
            long long leftSub = i - prevGr[i];  // how many choices to the left

            total += (rightSub * leftSub) * arr[i];
        }

        return total;
    }

    vector<int> nextGreater(vector<int>& arr, int n) {
        stack<int> s;
        vector<int> ans(n, n); // Default: no greater element to right

        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] < arr[i]) {
                ans[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }

        return ans;
    }

    vector<int> prevGreaterEqual(vector<int>& arr, int n) {
        stack<int> s;
        vector<int> ans(n, -1); // Default: no greater/equal element to left

        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] < arr[i]) {
                s.pop();
            }
            ans[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        return ans;
    }
};