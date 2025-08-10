class Solution {
private: 
    int mxArea = 0;
public:

    bool solve(int sr, int sc, int sqrLen, int m, int n, vector<vector<char>>& mat) {
        if(sr+sqrLen > m || sc+sqrLen > n)
            return false;

        for(int i = sr; i < sr+sqrLen; i++) {
            for(int j = sc; j < sc+sqrLen; j++) {
                if(mat[i][j] == '0')  
                    return false;
            }
        }

        return true;
    }

    bool checkSqr(int sqrLen, int m, int n, vector<vector<char>>& mat) {

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == '1') {
                    if(solve(i, j, sqrLen, m, n, mat)) {
                        mxArea = max(mxArea, sqrLen*sqrLen);
                        return true;
                    }
                }
            }
        }

        return false;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        // approach neive approach:
        // get MaxSquare we can obtain from given matrix by max(m, n)
        // try length of square from 0 to maxLength that we get 
        // then for each length check if such square exist or not

        // time complexity:O(m⋅n⋅min(m,n)^3)
        //  try square sizes from 1 to min(m, n) → up to O(min(m, n)) times.
        // For each square size k, you check all possible top-left positions → O(m * n).
        // For each such position, you check a k x k square → O(k^2).

        int m = matrix.size();
        int n = matrix[0].size();

        int mxSqr = min(m, n);

        int i = 0; 
        while(i <= mxSqr) {
            if(checkSqr(i, m, n, matrix)) {
                i++;
                continue;
            }
            else 
                break;
        }

        return mxArea;
    }
};