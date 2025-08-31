class Solution {
private:
    bool row[9][9] = {false};
    bool col[9][9] = {false};
    bool box[9][9] = {false};

public:
    void solveSudoku(vector<vector<char>>& board) {
        // initialize constraints from given board
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    row[i][num] = true;
                    col[j][num] = true;
                    box[(i/3)*3 + (j/3)][num] = true;
                }
            }
        }

        solve(0, 0, board);
    }

    bool solve(int r, int c, vector<vector<char>>& board) {
        for (int i = r; i < 9; i++) {
            for (int j = (i == r ? c : 0); j < 9; j++) {
                if (board[i][j] == '.') {
                    for (int num = 0; num < 9; num++) {
                        int boxIdx = (i/3)*3 + (j/3);
                        if (!row[i][num] && !col[j][num] && !box[boxIdx][num]) {
                            board[i][j] = num + '1';
                            row[i][num] = col[j][num] = box[boxIdx][num] = true;

                            if (solve(i, j + 1, board)) return true;

                            // backtrack
                            board[i][j] = '.';
                            row[i][num] = col[j][num] = box[boxIdx][num] = false;
                        }
                    }
                    return false; // no valid number for this cell
                }
            }
        }
        return true; // board filled successfully
    }

    // bool isValid(int r, int c, vector<vector<char>>& board, char ch) {
    //     for(int i = 0; i < 9; i++) {
    //         if(board[i][c] == ch)
    //             return false;
    //         if(board[r][i] == ch)
    //             return false;
    //         if(board[3 * (r/3) + i / 3][3 * (c/3) + i % 3] == ch)
    //             return false;
    //     }

    //     return true;
    // }
};   