class Solution {
public:

    void setRowZero(int r, int n, vector<vector<int>>& matrix) {
        for(int i = 0; i < n; i++)
            matrix[r][i] = 0;
    }

    void setColZero(int c, int m, vector<vector<int>>& matrix) {
        for(int i = 0; i < m; i++)
            matrix[i][c] = 0;
    }

    void setZeroes(vector<vector<int>>& matrix) {
        // first check if first row has to be set to 0 
        bool firstRowZero = false;
        bool firstColZero = false;

        int m = matrix.size();
        int n = matrix[0].size();

        for(int i = 0; i < n; i++) {
            if(matrix[0][i] == 0) {
                firstRowZero = true;
                break;
            }
        }

        for(int i = 0; i < m; i++) {
            if(matrix[i][0] == 0) {
                firstColZero = true;
                break;
            }
        }

        // now reserver the first row & first column & start from inner part
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                // if we see any 0 then set the representative  rows & cols box to 0
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // now set the entire column to 0 if the representative holds 0 value
        for(int i = 1; i < n; i++) {
            if(matrix[0][i] == 0) 
                setColZero(i, m, matrix);
        }

        for(int i = 0; i < m; i++) {
            if(matrix[i][0] == 0) 
                setRowZero(i, n, matrix);
        }

        // now time to check if the first row & col have to set to 0
        if(firstRowZero)
            setRowZero(0, n, matrix);
        if(firstColZero)
            setColZero(0, m, matrix);
    }
};