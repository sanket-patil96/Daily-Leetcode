class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        // we calculate for how many subarrays arr[i] can be the minimum and multiply total subarrays into arr[i]
        // so we can get the addition of minimums of that windows
        // we require couple of things, 1. NextSmaller, 2. PrevSmallerEqual

        int n = arr.size();
        int MOD = (int) (1e9 + 7);
        vector<int> nextSm = nextSmaller(arr, n);
        vector<int> prevSm = prevSmallerEqual(arr, n);

        int total = 0;

        for(int i = 0; i < n; i++) {
            int rightSub = nextSm[i] - i;
            int leftSub = i - prevSm[i];

            total = (total + (rightSub * leftSub * (long) arr[i]) % MOD) % MOD;
        }

        return total;
    }

    vector<int> nextSmaller(vector<int> &arr, int n) {
        stack<int> s;
        vector<int> ans(n, n); 

        for(int i = 0; i < n; i++) {
            while(s.size() && arr[s.top()] > arr[i]) {
                ans[s.top()] = i;
                s.pop();
            }

            s.push(i);
        }

        return ans;
    }

    
    vector<int> prevSmallerEqual(vector<int> &arr, int n) {
        stack<int> s;
        vector<int> ans(n, -1); 

        for(int i = 0; i < n; i++) {
            while(s.size() && arr[s.top()] > arr[i]) {
                s.pop();
            }

            ans[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        return ans;
    }
};