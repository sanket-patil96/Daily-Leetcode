class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        // sort array in descending order
        // maintain a delay variable, initialize with 0 initially, & increment after every iteration
        // while counting current value in answer also decrease the delay value from current happyness (don't make it negative) 

        int delay = 0;
        long long ans = 0;

        sort(happiness.rbegin(), happiness.rend());

        int i = 0;
        while(i < k) {
            int val = happiness[i] - delay < 0 ? 0 : happiness[i]-delay;
            ans += val;
            
            delay++;
            i++;
        }

        return ans;
    }
};