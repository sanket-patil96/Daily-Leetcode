class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        // same approach as: 1685. Sum of Absolute Differences in a Sorted Array

        int n = nums.size();
        unordered_map<int, vector<int>> groups;

        for (int i = 0; i < n; i++) {
            groups[nums[i]].push_back(i);
        }

        vector<long long> res(n);
        for (const auto& p : groups) {
            const auto& group = p.second;
            long long total = accumulate(group.begin(), group.end(), 0LL);
            long long prefixTotal = 0;

            for (int i = 0; i < group.size(); i++) {
                long long suffTotal = (total - prefixTotal - group[i]);
                long long leftSum = ((long long)group[i] * i) - prefixTotal;
                long long rightSum = suffTotal - ((long long)group[i] * (group.size()-1 - i));
                
                res[group[i]] = leftSum + rightSum;

                prefixTotal += group[i];
            }
        }

        return res;
    }
};