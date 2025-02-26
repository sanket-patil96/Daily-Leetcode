class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // better than neive: do binary search on every row

        for(int i = 0; i < matrix.size(); i++) {
            if(binary_search(matrix[i].begin(), matrix[i].end(), target))
                return true;
        }

        return false;
    }
};