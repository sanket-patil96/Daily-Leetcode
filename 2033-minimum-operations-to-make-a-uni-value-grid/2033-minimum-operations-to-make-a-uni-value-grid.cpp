class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        // 1. The number to reduce and increase all the elements to should be the median of the grid elements as it will be optimal to minimise operations
        // 2. convert 2D grid into 1D vector & sort it, so our median will be the middle  value of all other values
        // 3. traverse 1D array, take the absolute difference of current and median & if it doesn't completely divisible (diff % x != 0) then return -1, as all values can't be made similar using x as add/sub
        //    and to get the count of operations required to convert current to the median, do cnt += (diff / x)


        int n = grid.size();
        int m = grid[0].size();

        vector<int> arr;

        for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++)
                arr.push_back(grid[i][j]);

        sort(arr.begin(), arr.end());
        n = arr.size();

        int median = arr[n / 2];

        int totalOpr = 0;

        for(int i = 0; i < n; i++) {
            int diff = abs(arr[i] - median);
            if(diff % x != 0)   return -1;
            totalOpr += (diff / x);
        }

        return totalOpr;
    }
};