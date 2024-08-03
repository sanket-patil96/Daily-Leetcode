class Solution {
public:

    int tryRows(int row, int m, vector<vector<int>>& grid) {
        int start = 0, end = m-1;
        int flipCnt = 0;

        while(start < end) {
            if(grid[row][start] != grid[row][end])
                flipCnt++;

            start++;
            end--;
        }

        return flipCnt;
    }

    int tryCols(int col, int n, vector<vector<int>>& grid) {
        int start = 0, end = n-1;
        int flipCnt = 0;

        while(start < end) {
            if(grid[start][col] != grid[end][col])
                flipCnt++;

            start++;
            end--;
        }

        return flipCnt;
    }

    int minFlips(vector<vector<int>>& grid) {
        // we try to make both all rows palindromic or all columns palindromic
        // and return the minimum from them
        int n = grid.size();
        int m = grid[0].size();

        int flipRows = 0;
        int flipCols = 0;
        for(int i = 0; i < n; i++) {
            flipRows += tryRows(i, m, grid);        // row with its length
        }

        for(int j = 0; j < m; j++) {
            flipCols += tryCols(j, n, grid);
        }

        return min(flipRows, flipCols);
    }
};