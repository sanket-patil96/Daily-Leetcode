class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        // using max heap, so on top thir always remain higher value element that we can add up to
        // maximize score
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < nums.size(); i++)
            pq.push({nums[i], i});

        long long score = 0;

        while(k--) {
            pair<int, int> top = pq.top();
            pq.pop();
            score += top.first;
            nums[top.second] = ceil(nums[top.second] / 3.0);
            cout << nums[top.second] << "  " << endl;

            pq.push({nums[top.second], top.second});
        }

        return score;
    }
};