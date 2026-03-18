class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> prefSum = grid;
        int prevCol = 0, aboveCol = 0;

        for(int i = 0; i < n; i++) {
            prevCol = 0;        // set to 0 for first col of each new row

            for(int j = 0; j < m; j++) {
                aboveCol = i == 0 ? 0 : prefSum[i-1][j];
                int aboveDiagonal = (j == 0 || i == 0) ? 0 : prefSum[i-1][j-1];

                prefSum[i][j] += prevCol + aboveCol - aboveDiagonal;   // (addition of current col + prevCol + aboveCol) - left diagonal col
                prevCol = prefSum[i][j];
            }
        }

        int cnt = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(prefSum[i][j] <= k)
                    cnt++;
            }
        }

        return cnt;
    }
};