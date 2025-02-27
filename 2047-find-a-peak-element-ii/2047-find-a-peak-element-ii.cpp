class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        // The algorithm is as follows:

        // Pick the middle column.
        // Find the global maximum in the column.
        // If the row-neighbours of this element are smaller, then we found a 2D peak. Else, we recurse at the right-half of the matrix if the right-neighbour was bigger, and left-half of the matrix if the left-neighbour was bigger.

        int n = mat.size();
        int m = mat[0].size();
        int low = 0, high = m-1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            // find the index of the row elem that have greater value in it's column
            int maxRow = 0;
            for(int i = 0; i < n; i++) 
                if(mat[maxRow][mid] < mat[i][mid])  
                    maxRow = i;


            if((mid == 0 || mat[maxRow][mid] > mat[maxRow][mid-1]) &&
                (mid == m-1 || mat[maxRow][mid] > mat[maxRow][mid+1]))
                    return {maxRow, mid};


            // go to left side & eliminate right side
            else if(mid > 0 && mat[maxRow][mid-1] > mat[maxRow][mid]) 
                high = mid - 1;

            else 
                low = mid + 1;
        }

        return {-1, -1};
    }
};