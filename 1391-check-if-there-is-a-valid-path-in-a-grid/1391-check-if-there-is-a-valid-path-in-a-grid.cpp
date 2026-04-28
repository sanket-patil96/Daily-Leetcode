class Solution {
private: 
    int dir[5] = {-1, 0, 1, 0, -1};
    char side[4] = {'U', 'R', 'D', 'L'};        // side on which we are going

public:
    bool hasValidPath(vector<vector<int>>& grid) {
        // at the current path there are several options for connectivity, either left-right / up-down / up-right / left-up / down-left / left-down
        // we can explore accordingly to reach the bottom right corner
        // so from current street (exp1) at (0,0) we can move to down street, coz they are connecting
        // while in exp2, there is no connectivity!

        // we just need to know from current street wheather we are moving to above/left/right/down, so we have to check the connectivity
        // coz from street 1 we can reach to street3, but only if its in right side of street1
        
        return solve(0, 0, grid);
    }

    bool solve(int r, int c,  vector<vector<int>>& grid) {
        if(r == grid.size()-1 && c == grid[0].size()-1)
            return true;

        // mark current street as visited  so we don't  come here again on same path
        int original = grid[r][c];
        grid[r][c] = -1;

        // check where we can go from current street
        for(int i = 0; i < 4; i++) {
            int newR = r + dir[i];
            int newC = c + dir[i+1];

            if(canReach(original, newR, newC, side[i], grid)) {
                if(solve(newR, newC, grid))
                    return true;
            }
        }
        
        grid[r][c] = original;      // reseat the change for next path explorations
        return false;
    }

    bool canReach(int street, int r, int c, char side, vector<vector<int>>& grid) {
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == -1)
            return false;

        // from current street find if we can go to street X on give side!!!

        int x = grid[r][c];       // on this street we are  trying to  go

        if(street == 1) {
            if(side == 'U' || side == 'D')  return false;

            if(side == 'L' && (x == 1 || x == 4 || x == 6))  return true;
            if(side == 'R' && (x == 1 || x == 3 || x == 5))  return true;
        }
        
        if(street == 2) {
            if(side == 'L' || side == 'R')  return false;

            if(side == 'U' && (x == 2 || x == 3 || x == 4))  return true;
            if(side == 'D' && (x == 2 || x == 6 || x == 5))  return true;
        }
        
        if(street == 3) {
            if(side == 'U' || side == 'R')  return false;

            if(side == 'L' && (x == 1 || x == 4 || x == 6))  return true;
            if(side == 'D' && (x == 2 || x == 5 || x == 6))  return true;
        }
        
        if(street == 4) {
            if(side == 'U' || side == 'L')  return false;

            if(side == 'D' && (x == 2 || x == 5 || x == 6))  return true;
            if(side == 'R' && (x == 1 || x == 3 || x == 5))  return true;
        }

        if(street == 5) {
            if(side == 'R' || side == 'D')  return false;

            if(side == 'L' && (x == 1 || x == 4 || x == 6))  return true;
            if(side == 'U' && (x == 2 || x == 3 || x == 4))  return true;
        }

        if(street == 6) {
            if(side == 'L' || side == 'D')  return false;

            if(side == 'U' && (x == 2 || x == 3 || x == 4))  return true;
            if(side == 'R' && (x == 1 || x == 3 || x == 5))  return true;
        }

        return false;
    }
};