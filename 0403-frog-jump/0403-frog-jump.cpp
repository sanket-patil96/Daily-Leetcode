class Solution {
public:
    bool canCross(vector<int>& stones) {
        // from current stone we have 3 choices, according to k
        // i.e k-1, k, k+1 jumps so we try all jumps and check if any one path can reach to last stone
        int n = stones.size();
        if(n <= 1)
            return true; 

        // initial k value must be 1
        if(stones[1] - stones[0] > 1)
            return false;

        // to memoize, changing parameters are 2, i.e i and k, the result is depend on k so it need to be considered!
        vector<vector<int>> memo(n, vector<int>(2000, -1));        // at max the gap can be 2000 (according to constraints)

        int k = 1;
        return solve(1, k, n, memo, stones);      // starting position is stone 1
    }

    bool solve(int i, int k, int n, vector<vector<int>> &memo, vector<int>& arr) {
        if(i == n-1)
            return true;        // reach the last stone
        
        if(memo[i][k] != -1)
            return memo[i][k];

        // we have 3 options for jumping from here
        int j1 = k-1, j2 = k, j3 = k+1;
        bool jump1 = false, jump2 = false, jump3 = false;
        
        // check if the required gap between stones equals the k, if yes then get index
        // lower_bound to find an iterator to the target value (or next greater)
        auto it1 = lower_bound(arr.begin()+i+1, arr.end(), arr[i]+j1);
        auto it2 = lower_bound(arr.begin()+i+1, arr.end(), arr[i]+j2);
        auto it3 = lower_bound(arr.begin()+i+1, arr.end(), arr[i]+j3);

        if(it1 != arr.end() && *it1 == arr[i]+j1)
            jump1 = solve(it1 - arr.begin(), j1, n, memo, arr);

        if(it2 != arr.end() && *it2 == arr[i]+j2) 
            jump2 = solve(it2 - arr.begin(), j2, n, memo, arr);

        if(it3 != arr.end() && *it3 == arr[i]+j3) 
            jump3 = solve(it3 - arr.begin(), j3, n, memo, arr);
        

        return memo[i][k] = (jump1 || jump2 || jump3);
    }
};