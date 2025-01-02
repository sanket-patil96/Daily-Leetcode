class Solution {
private: 
    // for up, right, down, left, use: current ind = row, & next ind = col
    int dist[5] = {-1, 0, 1, 0, -1};

public:
    void dfs(int r, int c, int n, int m, vector<vector<char>>& board) {
        // return if out of boundry
        if(r < 0 || c < 0 || r >= n || c >= m || board[r][c] != 'O')
            return;

        // mark it as visited
        board[r][c] = '1';

        // travel to neighbouring cells
        for(int i = 0; i < 4; i++)
            dfs(r+dist[i], c+dist[i+1], n, m, board);
    }

    void solve(vector<vector<char>>& board) {
        // we think in reverse- start from all surrounded regions and
        // mark them 1 & use flood fill to move to its adjacents & mark them also 1
        // at last we again loop in board & if there we found 'O' means it is not reachable from boundry region cells
        // so that its not converted to -1, So make it as surrounded region by marking it with 'X'
        // and reseat 1's to again O;

        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) 
                // start dfs only when its a boundry cell & with value = 0
                if((i * j == 0 || i == n-1 || j == m-1) && board[i][j] == 'O')
                    dfs(i, j, n, m, board);


        // reseat the board for '1's & make 'O' to  OR 'O' to 'X'
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                if(board[i][j] == '1')
                    board[i][j] = 'O';
            }
        }
    }
};