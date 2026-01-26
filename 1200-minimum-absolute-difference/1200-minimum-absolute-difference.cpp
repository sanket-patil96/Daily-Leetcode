class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        // find the minimum absolute difference first
        // then find the pairs that have that absolute diff
        // we need to sort in ascending  so, min diff = diff between any 2 adjacnet elements

        sort(arr.begin(), arr.end());
        int minDiff = abs(arr[0] - arr[1]);

        for(int i = 1; i < arr.size()-1; i++) {
            minDiff = min(minDiff, abs(arr[i] - arr[i+1]));
        }

        // now find the pairs
        vector<vector<int>> ans;
        for(int i = 0; i < arr.size(); i++) {
            // don't need to travel whole array, stop when current pair's diff > minDiff
            for(int j = i+1; j < arr.size(); j++) {
                int diff = abs(arr[i]-arr[j]);
                if(diff == minDiff)
                    ans.push_back({arr[i], arr[j]});
                if(diff > minDiff)
                    break;
            }
        }

        return ans;
    }
};