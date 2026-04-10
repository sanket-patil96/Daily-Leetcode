class Solution {
private:
    int dir[5] = {-1, 0, 1, 0, -1};

public:

    int dfs(int id, int r, int c, int n, vector<vector<int>>& grid) {
        if(r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != 1) 
            return 0;

        int cnt = 1;
        grid[r][c] = id;        // visit with its unique id

        for(int i = 0; i < 4; i++)
            cnt += dfs(id, r+dir[i], c+dir[i+1], n, grid);

        return cnt;
    }

    unordered_set<int> cntNeighbourIslands(int r, int c, int n, vector<vector<int>>& grid) {

        // using set to count the different(unique) islands around current cell, 
        // coz it can happen that same island can be spread in multiple directeion
        unordered_set<int> s;       

        // check 4 directions if there are any islands
        if(r-1 >= 0 && grid[r-1][c] != 0)
            s.insert(grid[r-1][c]);

        if(r+1 < n && grid[r+1][c] != 0)
            s.insert(grid[r+1][c]);

        if(c-1 >= 0 && grid[r][c-1] != 0)
            s.insert(grid[r][c-1]);
            
        if(c+1 < n && grid[r][c+1] != 0)
            s.insert(grid[r][c+1]);

        return s;
    }

    int largestIsland(vector<vector<int>>& grid) {
        // 1. give unique id to each island, & store the island size in map with currosponding ID
        // 2. start checking all 0's, if a 0 has more than 1 island neighbours, count the maxArea possible
        // 3. return the overall maxArea

        int n = grid.size();
        int id = 2;                 // should start from 2 coz 0 & 1 already in grid
        unordered_map<int, int> isLandArea;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    int size = dfs(id, i, j, n, grid);
                    isLandArea[id++] = size;
                }
            }
        }


        int maxArea = -1;
        // now check for 0 cells, who have more than 1 neighbour islands, 

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    unordered_set<int> s = cntNeighbourIslands(i, j, n, grid);
                    cout << s.size() << endl;

                    int area = 1;       // initial 1 for current 0 cell converted to land
                    for(auto a: s)
                        area += isLandArea[a];      

                    maxArea = max(maxArea, area);
                }
            }
        }
        
        // if there is no water cell then the total land is n*n
        return maxArea == -1 ? n*n : maxArea;
    }
};