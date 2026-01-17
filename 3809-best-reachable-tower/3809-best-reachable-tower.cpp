class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        int x = -1, y = -1, maxQuality = INT_MIN;

        for(auto &t: towers) {
            int dist = abs(center[0]-t[0]) + abs(center[1]-t[1]);
            
            if(dist <= radius) {
                if(maxQuality < t[2]) {
                    x = t[0];
                    y = t[1];
                    maxQuality = t[2];
                }

                // take nearest tower
                else if(maxQuality == t[2]) {
                    if(t[0] < x || (t[0] <= x && t[1] < y)) {
                        x = t[0];
                        y = t[1];
                    }
                }
            }
        }

        if(maxQuality == INT_MIN)
            return {-1, -1};

        return {x, y};
    }
};