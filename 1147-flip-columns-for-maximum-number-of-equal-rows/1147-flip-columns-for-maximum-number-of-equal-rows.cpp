// class Solution {
// public:
//     int checkMaxSameRows(vector<vector<int>>& mat, int n, int m) {
//         int cnt = 0;

//         for(int i = 0; i < n; i++) {
//             bool allEqual = true;
//             for(int j = 1; j < m; j++) {
//                 // check if this column match with previous one in same row
//                 if(mat[i][j] != mat[i][j-1]) {      
//                     allEqual = false;
//                     break;
//                 }
//             }

//             if(allEqual)
//                 cnt++;
//         }

//         return cnt;
//     }

//     void flipCol(vector<vector<int>>& mat, int n, int c) {
//         for(int i = 0; i < n; i++)
//             mat[i][c] = mat[i][c] == 0 ? 1 : 0;
//     }

//     int solve(int r, int c, vector<vector<int>>& mat, int n, int m) {
//         if(c >= m)
//             return 0;

//         int flip, noFlip;
//         for(int col = c; col < m; col++) {
//             // there are 2 ways to check, by fliping current col or not fliping it 
//             noFlip = checkMaxSameRows(mat, n, m);
//             solve(r, col+1, mat, n, m);

//             flipCol(mat, n, col);
//             solve(r, col+1, mat, n, m);
//             flip = checkMaxSameRows(mat, n, m);
//             // reseat matrix for next usage
//             flipCol(mat, n, col);
//         }

//         return max(noFlip, flip);
//     }


//     int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
//         // this not worked!!!
//         // we have to check each column by fliping and also checks further columns after this
//         // do same for all columns fliping possibility
//         int n = matrix.size();
//         int m = matrix[0].size();

//         return solve(0, 0, matrix, n, m);
//     }
// };

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        // idea is based on: we have to find either rows that are completely opposite or rows that are same

        int numCols = matrix[0].size();
        int maxIdenticalRows = 0;

        for (auto& currentRow : matrix) {
            // Create vector to store flipped version of current row
            vector<int> flippedRow(numCols);
            int identicalRowCount = 0;

            // Create flipped version of current row (0->1, 1->0)
            // if original = 0101 then fliped = 1010 so any row will match any of this version, we will incremetn the coutner
            for (int col = 0; col < numCols; col++) {
                flippedRow[col] = 1 - currentRow[col];
            }

            // Check every row against current row and its flipped version
            for (auto& compareRow : matrix) {
                // If row matches either original or flipped pattern, increment counter
                // like comparing = 0000, current = 1111 || comparing = 0000 & current = 0000
                // so when we flip specific cols it will get matched
                if (compareRow == currentRow || compareRow == flippedRow) {
                    identicalRowCount++;
                }
            }

            maxIdenticalRows = max(maxIdenticalRows, identicalRowCount);
        }

        return maxIdenticalRows;
    }
};