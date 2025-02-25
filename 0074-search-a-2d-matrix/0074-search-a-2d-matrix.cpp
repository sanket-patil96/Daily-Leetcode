class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // approach: time: O(rows * log(m)), have to check check every row range & run search on specific row
        // check in which row the answer can be found
        // then binary search on that row 

        int m = matrix[0].size();

        for(int i = 0; i < matrix.size(); i++) {
            if(target >= matrix[i][0] && target <= matrix[i][m-1])
                return binary_search(matrix[i].begin(), matrix[i].end(), target);
        }

        return false;
    }
};