class neighborSum {
public:
    vector<vector<int>> grid;
    
    neighborSum(vector<vector<int>>& grid) {
        this->grid = grid;
    }
    
    int getAdjacentSum(int row, int col, vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size();
        int sum = 0;
        
        // get top down left right values
        if(row - 1 >= 0)
            sum += grid[row-1][col];
        
        if(row + 1 < n)
            sum += grid[row+1][col];
        
        if(col - 1 >= 0)
            sum += grid[row][col-1];
        
        if(col + 1 < m)
            sum += grid[row][col+1];
        
        return sum;
    }
    
    int getDiagonalSum(int row, int col, vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size();
        int sum = 0;
        
        // get top-left top-right bottom-left bottom-right
        if(row - 1 >= 0 && col -1 >= 0)
            sum += grid[row-1][col-1];
        
        if(row - 1 >= 0 && col + 1 < m)
            sum += grid[row-1][col+1];
        
        if(row + 1 < n && col - 1 >= 0)
            sum += grid[row+1][col-1];
        
        if(row + 1 < n && col + 1 < m)
            sum += grid[row+1][col+1];
        
        return sum;
    }
    
    
    int adjacentSum(int value) {
        for(int i = 0; i < this->grid.size(); i++) {
            for(int j = 0; j < this->grid[0].size(); j++) {
                if(this->grid[i][j] == value) {
                    return getAdjacentSum(i, j, this->grid);
                }
            }
        }
        
        return -1;
    }
    
    int diagonalSum(int value) {
        for(int i = 0; i < this->grid.size(); i++) {
            for(int j = 0; j < this->grid[0].size(); j++) {
                if(this->grid[i][j] == value) {
                    return getDiagonalSum(i, j, this->grid);
                }
            }
        }
        
        return -1;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */