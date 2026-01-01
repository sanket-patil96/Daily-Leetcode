class Solution {
private:
public:
    bool canCross(vector<int>& stones) {
        // more optimised over binary search, using map
        
        // from current stone we have 3 choices, according to k
        // i.e k-1, k, k+1 jumps so we try all jumps and check if any one path can reach to last stone
        int n = stones.size();
        if(n <= 1)
            return true; 

        // initial k value must be 1
        if(stones[1] - stones[0] > 1)
            return false;

        // to memoize, changing parameters are 2, i.e i and k, the result is depend on k so it need to be considered!
        vector<vector<int>> memo(n, vector<int>(2001, -1));        // at max the gap can be 2000 (according to constraints)

        unordered_map<long long, int> mp;
        for(int i = 0; i < n; i++)
            mp[stones[i]] = i;          // all values are unique in stones (strictly increasing order)

        int k = 1;
        return solve(1, k, mp, memo, stones);      // starting position is stone 1
    }

    bool solve(int i, int k, unordered_map<long long, int> &mp, vector<vector<int>> &memo, vector<int>& arr) {
        if(i == arr.size()-1)
            return true;        // reach the last stone
        
        if(k < 0)
            return false;       // to avoid negative indexing

        if(memo[i][k] != -1)
            return memo[i][k];

        // we have 3 options for jumping from here
        int j1 = k-1, j2 = k, j3 = k+1;
        bool jump1 = false, jump2 = false, jump3 = false;

        // check if the required gap between stones equals the k, if yes then get index

        if(j1 > 0 && mp.count(long(arr[i])+j1))
            jump1 = solve(mp[arr[i]+j1], j1, mp, memo, arr);

        if(mp.count(long(arr[i])+j2))
            jump2 = solve(mp[arr[i]+j2], j2, mp, memo, arr);

        if(mp.count(long(arr[i])+j3))
            jump3 = solve(mp[arr[i]+j3], j3, mp, memo, arr);


        return memo[i][k] = (jump1 || jump2 || jump3);
    }
};