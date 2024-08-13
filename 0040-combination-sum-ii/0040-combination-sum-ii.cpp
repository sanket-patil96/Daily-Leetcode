class Solution {
public:
    void solve(int ind, int target, vector<int> temp, vector<vector<int>> &ans, vector<int>& candidates) {
        if(target == 0) {
            ans.push_back(temp);
        }

        for(int i = ind; i < candidates.size(); i++) {
            if(i > ind && candidates[i] == candidates[i-1])
                continue;

            if(candidates[i] <= target) 
            {
                temp.push_back(candidates[i]);
                solve(i+1, target-candidates[i], temp, ans, candidates);
                temp.pop_back();
            }

            // don't need to call with further values coz array is sorted, current value is > target 
            // then next values also greater so no futher calls required!
            else 
                break;
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> combinations;
        vector<int> temp;

        solve(0, target, temp, combinations, candidates);
        return combinations;
    }
};