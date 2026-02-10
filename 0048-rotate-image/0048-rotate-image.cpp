class Solution {
public:
    
    void rotate(vector<vector<int>>& matrix) {
        // notice the index changes in matrix, in ip/op
        // we have to swap the i,j index values, 
        // then after reversing it will look like 90 degree rotation
        
        int n = matrix.size();
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {                   // start j from to avoid re-swaping of already swapped values
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // reverse every row
        for(int i = 0; i < n; i++) 
            reverse(matrix[i].begin(), matrix[i].end());
    }
};