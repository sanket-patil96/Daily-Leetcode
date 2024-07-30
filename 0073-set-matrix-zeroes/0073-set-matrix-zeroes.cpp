class Solution {
public:

    void setZeroes(vector<vector<int>>& matrix) {
        // method 2: time o(m*n)  space: O(1)
        // method 2: using col[0] & row[0] as we used 2 sets in previous solution
        // more explanation in book

        int n = matrix.size();
        int m = matrix[0].size();
        int col0 = 1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0) {
                    // we put 0 on that row
                    matrix[i][0] = 0;

                    // we can't do same for col, here we have to check if its not 0th col, coz making it
                    // 0 will coz whole first row to become 0 unneccessorrily
                    if(j != 0) 
                        matrix[0][j] = 0;
                    else 
                        col0 = 0;       // if its first column to set to 0 then we set col0 to 0
                }
            }
        }

        // now we don't start from 0th row & col coz we have set there which row & col should  become 0
        // using that info we will convert our matrix to zeros
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(matrix[i][j] != 0) {                     // only check for non-zero elements
                    if(matrix[i][0] == 0 || matrix[0][j] == 0)       // if row OR col has set to 0 for this position then make it 0
                        matrix[i][j] = 0;
                }
            }
        }

        // now set first row & col to their desired result
        // if first element of row set to 0 means whole row to be set to 0
        if(matrix[0][0] == 0)           
            for(int col = 0; col < m; col++)
                matrix[0][col] = 0;
        
        // col0 = 0 means that col should be filled with 0
        if(col0 == 0)
            for(int row = 0; row < n; row++)
                matrix[row][0] = 0;
        
    }
};