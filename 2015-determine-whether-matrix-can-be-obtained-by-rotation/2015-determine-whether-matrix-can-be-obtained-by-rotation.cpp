class Solution {
public:
    void rotate90(vector<vector<int>>& mat) {
        // transpose matrix
        for(int i = 0; i < mat.size(); i++) {
            // start j with i coz if start from 0 everytime, then it will again 
            // transpose some already transposed elements (dry run it)
            for(int j = i+1; j < mat.size(); j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }

        // now rever the rows
        for(int i = 0; i < mat.size(); i++) {
            reverse(mat[i].begin(), mat[i].end());
        }
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        // 90 deg rotation means:
        // mat[i][j] -> mat[j][n-i-1]
        // We know transpose is:
        // mat[i][j] -> mat[j][i]
        // Now we see row is good and column to be reversed. So reversing rows gives:
        // mat[j][i] -> mat[j][n-i-1]

         // Check the matrix in all 4 possible rotations
        for (int i = 0; i < 4; ++i) {
            if (mat == target)
                return true;
            
            rotate90(mat);
        }
        
        return false;
    }
};