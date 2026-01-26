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

        for(int i = 0; i < arr.size()-1; i++) {
            // min diff can only be found in adjacents, as we have sorted the array
            if(abs(arr[i]-arr[i+1]) == minDiff)
                ans.push_back({arr[i], arr[i+1]});
        }

        return ans;
    }
};