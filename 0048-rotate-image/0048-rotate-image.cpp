class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // rotating matrix by 90 degree means making columns as rows, like:
        // column from bottom to up becomes row
        // brute force: creating dummy matrix & fill it as per foumula & then copy to mat
        // time: O(n^2) space: O(n^2) for dummy matrix
        
        // optimal solution: transpose the matrix & then reverse each row, time: O(n/2*n/2) + O(n * n/2) space: O(1)
        // after transposing digonal elements remains same, so don't need to consider them
        // observation: 
        // after transposing matrix, we just need to reverse each row
        int n = matrix.size();
        int m = matrix[0].size();

        // transpose matrix, escaping already transposed positions by  j=i+1
        // time: O(n/2 * n/2)
        for(int i = 0; i < n; i++)
            // start j with i+1 coz if start from 0 everytime, then it will again 
            // transpose some already transposed elements (dry run it) (not j = i also coz it will be the same after transpose also)
            for(int j = i+1; j < m; j++)
                swap(matrix[i][j], matrix[j][i]);


        // reverse each row, time: O(n * n/2)
        for(int i = 0; i < n; i++)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};