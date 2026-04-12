class Solution {
public:
    int minimumDistance(string word) {
        // there  are 2 choices to type a single  character
        // either type with finger 1 or with finger 2
        // kinda similar with take/noTake approach
        // try both choices and get minimum

        // now convert it to Memoization:
        // changing states are: i, f1r, f1c, f2r, f2c
        // their sizes are: N for indices, 5 for rows, 6 for cols
        // we need index shifting as our finger1 & finger 2 coordinates are on -1 initially so
        // it will give error when we try to access them inside dp array
        // so +1 for all of the coordinates of fingers for dp array only

        int n = word.size();
        vector<vector<vector<vector<vector<int>>>>> dp(n+1,
            vector<vector<vector<vector<int>>>>(5+1,      // max size of row
                vector<vector<vector<int>>>(6+1,          // max size of col
                    vector<vector<int>>(5+1,
                        vector<int>(6+1, -1) // initialize with 0
                    )
                )
            )
        );

        // first create mapping of character with  its  coordinates
        unordered_map<char, pair<int,  int>> m;
        char ch = 'A';
        int row = 0, col = 0;

        while(ch <= 'Z') {
            m[ch] = {row, col};
            ch++;   
            col++;

            // goes to next row when reach the end of columns of current row
            if(col == 6) {
                col = 0;
                row++;
            }
        }

        // index for word, {coordinates for finger1, finger2}, map
        return solve(0, -1, -1, -1, -1, m, word, dp);
    }

    int solve(int i, int f1r, int f1c, int f2r, int f2c, unordered_map<char, pair<int, int>> &mp, string &word, vector<vector<vector<vector<vector<int>>>>> &dp) {
        if(i == word.size())
            return 0;

        if(dp[i][f1r+1][f1c+1][f2r+1][f2c+1] != -1)     // can't access -1, so shif the indexes of coordinates
            return dp[i][f1r+1][f1c+1][f2r+1][f2c+1];
        
        // get the coordinates of character
        auto [row, col] = mp[word[i]];

        // try to type with both fingers 
        int finger1 = 0, finger2 = 0;

        // f1r / f2r == -1 means fingers arent set yet, so cost for first typed value will be 0
        if(f1r == -1)
            finger1 = 0 + solve(i+1, row, col, f2r, f2c, mp, word, dp);
        else {
            int diff = abs(row - f1r) + abs(col - f1c);
            finger1 = diff + solve(i+1, row, col, f2r, f2c, mp, word, dp);      // replace coordinates for finger 1, as this character typed with finger 1
        }
        
        if(f2r == -1)
            finger2 = 0 + solve(i+1, f1r, f1c, row, col, mp, word, dp);
        else {
            int diff = abs(row - f2r) + abs(col - f2c);
            finger2 = diff + solve(i+1, f1r, f1c, row, col, mp, word, dp);
        }

        return dp[i][f1r+1][f1c+1][f2r+1][f2c+1] = min(finger1, finger2);
    }
};