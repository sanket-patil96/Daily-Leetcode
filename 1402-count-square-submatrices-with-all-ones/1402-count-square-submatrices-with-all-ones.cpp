class Solution {
    int ans = 0;
public:

    int countSquares(vector<vector<int>>& matrix) {
        // same approach of maximal square
        return maximalSquare(matrix);
    }

    int maximalSquare(vector<vector<int>>& matrix) {
        // brute force approach:
        // get MaxSquare we can obtain from given matrix by max(m, n)
        // try length of square from 0 to maxLength that we get 
        // then for each length check if such square exist or not

        // time complexity:O(m⋅n⋅min(m,n)^3)
        // try square sizes from 1 to min(m, n) → up to O(min(m, n)) times.
        // For each square size k, you check all possible top-left positions → O(m * n).
        // For each such position, you check a k x k square → O(k^2).

        int m = matrix.size();
        int n = matrix[0].size();

        int mxSqr = min(m, n);

        int i = 1; 
        while(i <= mxSqr) {
            if(checkSqr(i, m, n, matrix)) {
                cout << i << " cnt: " << ans << endl;
                i++;
            }
            else 
                break;
        }

        return ans;
    }

    bool checkSqr(int sqrLen, int m, int n, vector<vector<int>>& mat) {
        bool flag = false;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 1) {
                    if(solve(i, j, sqrLen, m, n, mat)) {
                        ans++;    // if current square is forming then add 1 to answer
                        flag = true;
                    }
                }
            }
        }

        return flag;
    }

    
    bool solve(int sr, int sc, int sqrLen, int m, int n, vector<vector<int>>& mat) {
        if(sr+sqrLen > m || sc+sqrLen > n)
            return false;

        for(int i = sr; i < sr+sqrLen; i++) {
            for(int j = sc; j < sc+sqrLen; j++) {
                if(mat[i][j] == 0)  
                    return false;
            }
        }

        return true;
    }
};