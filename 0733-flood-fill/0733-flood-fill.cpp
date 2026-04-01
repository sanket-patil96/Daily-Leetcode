class Solution {
private:
    int dir[5] = {-1, 0, 1, 0, -1};
public:

    void dfs(int sr, int sc, int OGClr, int targetClr, int n, int m, vector<vector<int>>& image) {
        if(sr >= n || sc >= m || sr < 0 || sc < 0 || image[sr][sc] != OGClr || image[sr][sc] == targetClr)
            return;

        image[sr][sc] = targetClr;

        for(int i = 0; i < 4; i++)
            dfs(sr+dir[i], sc+dir[i+1], OGClr, targetClr, n, m, image);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(); 
        int m = image[0].size();


        // original color is the color of source(starting) pixel, so all adjacents must be of that color 
        int originalClr = image[sr][sc];

        // if they same then don't need to change anything
        if(originalClr == color) return image;
        
        dfs(sr, sc, originalClr, color, n, m, image);
        return image;
    }
};